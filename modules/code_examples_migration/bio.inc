<?php

/**
 * @file
 *
 * Class definition for the Bio migration.
 */

/**
 * Class MigrateArticleMigration
 */
class MigrateBioMigration extends XMLMigration {
  /**
   * Set up source to destination mappings and XML XPath
   *
   * @param array $arguments
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $options = $arguments['options'];
    $format = $arguments['format'];

    $this->description = t('Migrate Article content into Drupal.');

    $items_url = drupal_get_path('module', 'code_examples') . '/src/migrate/biography.xml';
    $item_xpath = '/database/select/row';
    $item_ID_xpath = 'INDEX';

    $fields = array(
      'title' => t('Biography Title'),
      'description' => t('Description'),
      'article' => t('Referenced Article'),
    );

    //Options
    $this->source = new MigrateSourceXML($items_url, $item_xpath, $item_ID_xpath, $fields, $options);

    // We migrate into "biography" nodes.
    $this->destination = new MigrateDestinationNode('biography');

    // We instantiate the MigrateMap
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'INDEX' => array('type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
          'description' => 'Unique identifier',
        )
      ),
      MigrateDestinationNode::getKeySchema('biography')
    );

    $this->addFieldMapping('title', 'title')
      ->xpath('TITLE');

    $this->addFieldMapping('body:format')->defaultValue($format);
    $this->addFieldMapping('body', 'description')
      ->xpath('DESCRIPTION');

    $this->addFieldMapping('field_biography_article', 'article')
      ->xpath('ARTICLE');

  }

  /**
   * Override parent::prepareRow to customise mappings and prevent duplicate courses
   *
   * @param $row
   * @return bool TRUE to submit new node, FALSE to abort new entry
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    //Get Article by Title
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'article')
      ->propertyCondition('title', $row->xml->ARTICLE, '=');
    $result = $query->execute();

    if (isset($result['node'])) {
      $item_nid = array_keys($result['node']);
      $row->xml->ARTICLE = reset($item_nid);
    }

    return TRUE;
  }

}