<?php

/**
 * @file
 *
 * Class definition for the Article migration.
 */

/**
 * Class MigrateArticleMigration
 */
class MigrateArticleMigration extends XMLMigration {
  public $tax_separator = ';';
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

    $items_url = drupal_get_path('module', 'code_examples') . '/src/migrate/article.xml';
    $item_xpath = '/database/select/row';
    $item_ID_xpath = 'INDEX';

    $fields = array(
      'title' => t('Article Title'),
      'tags' => t('Article taxonomy tags'),
      'description' => t('Description'),
      'image' => t('Image'),
    );

    //Options
    $this->source = new MigrateSourceXML($items_url, $item_xpath, $item_ID_xpath, $fields, $options);

    // We migrate into "article" nodes.
    $this->destination = new MigrateDestinationNode('article');

    // We instantiate the MigrateMap
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'INDEX' => array('type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
          'description' => 'Unique identifier',
        )
      ),
      MigrateDestinationNode::getKeySchema('article')
    );

    $this->addFieldMapping('title', 'title')
      ->xpath('TITLE');

    $this->addFieldMapping('field_tags:create_term')->defaultValue(TRUE);
    $this->addFieldMapping('field_tags', 'tags')
      ->xpath('CATEGORY')
      ->separator($this->tax_separator);

    $this->addFieldMapping('body:format')->defaultValue($format);
    $this->addFieldMapping('body', 'description')
      ->xpath('DESCRIPTION');

    $this->addFieldMapping('field_image', 'image')
      ->xpath('IMAGE');
    $this->addFieldMapping('field_image:file_class')
      ->defaultValue('MigrateFileUri');
    $this->addFieldMapping('field_image:source_dir')
      ->defaultValue(drupal_get_path('module', 'code_examples') . '/src/migrate/img');
  }

}