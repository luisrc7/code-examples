<?php

/**
 * @file
 * Include file with common functions used in the module code.
 */

/**
 * Get the Sub Modules names from the Code Examples Module.
 * @return array
 *  Array or Sub Module names.
 */
function ce_get_submodules() {
  $dir = new DirectoryIterator(drupal_get_path('module', 'code_examples') . '/modules');
  $sub_modules = array();
  foreach ($dir as $fileinfo) {
    if (!$fileinfo->isDot() && $fileinfo->isDir()) {
      $sub_modules[] = $fileinfo->getFilename();
    }
  }
  return $sub_modules;
}

/**
 * Get the Sub Module description from a given name.
 * @param String $subModule
 *  The name of the Sub Module.
 * @return null|string
 *  Return the HTML output for the Sub Module description.
 */
function ce_submoduce_description($sub_module) {

  switch ($sub_module) {
    case 'code_examples_last_viewed':
      $description = t('This module logs the timestamp of the last time the author
        of a node visited the "view node" page.');
      $description .= "<br />";
      $description .= t('This module creates a custom table in the database where
        the "view" is logged and then retrieved.');
      $description .= "<br />";
      $description .= t('This module was developed for a use case where the author
        of the node had to quick view when was the last time the node was visited.');
      $description .= "<br />";
      $description .= t('Also the system interacted with this module to present some
        alerts if there was an external action after the node was last viewed, for
        example alert the author that your node has been modified by another person.');
      return $description;
      break;
    case 'code_examples_migration':
      $description = t('This module is an example of a migration class.');
      $description .= "<br />";
      $description .= t('I have used migrations to import different kind of content
        into a Drupal sites like related entities, images or files or simple text
        field into Drupal nodes.');
      $description .= "<br />";
      $description .= t('In this example I will import 2 static XML files
        you can find the files in code_examples/src/migrate into 2 related Drupal
        entities, using an entityreference field.');
      $description .= "<br />";
      $description .= t('I will create a new Content Type programmatically as well
        for one of these migrations and use the Article for the other.');
      $description .= "<br />";
      $description .= t('This module requires:');
      $description .= "<ul>";
      $description .= "<li>";
      $description .= t('Migrate contrib module.');
      $description .= "</li>";
      $description .= "<li>";
      $description .= t('Entitireference contrib module.');
      $description .= "</li>";
      $description .= "</ul>";
      return $description;
      break;
    case 'code_examples_overlay_load':
      $description = t('This module is an example of Overlay content.');
      $description .= "<br />";
      $description .= t('I have used overlays in projects where we had to display
        lots of information and the designers didn\'t want to present an interface
        to the final user where they have to click and go back and click again.');
      $description .= "<br />";
      $description .= t('In this example provided I will reuse the existing "code_examples_packzip_files"
        module to modify it\'s behaviour.');
      $description .= "<br />";
      $description .= t('I will present the second interface of selected nodes into
        an overlay and close it automatically when generate the file to download.');
      $description .= "<br />";
      $description .= t('This module requires:');
      $description .= "<ul>";
      $description .= "<li>";
      $description .= t('code_examples_packzip_files enabled from this Code Examples.');
      $description .= "</li>";
      $description .= "<li>";
      $description .= t('Colorbox contrib module. (Libraries + colorbox library as well)');
      $description .= "</li>";
      $description .= "<li>";
      $description .= t('Colorbox Node contrib module.');
      $description .= "</li>";
      $description .= "</ul>";
      return $description;
      break;
    case 'code_examples_packzip_files':
      $description = t('This module is an example of pack and zip files together.');
      $description .= "<br />";
      $description .= t('I have used this functions to pack and zip files in a project
        where the user can select different Products and download all the specification
        files at once in a .zip file.');
      $description .= "<br />";
      $description .= t('I used also an option to email the link to the packed files
        so the user would be able to download the files later.');
      $description .= "<br />";
      $description .= t('In this example code I have created two listing interfaces,
        the first one list all the website content and you can select different nodes
        once you selected some nodes you are presented a second interface with only
        the selected module that contain files (files or images) and you can select
        again and download the files in a packed .zip file.');
      $description .= "<br />";
      $description .= t('You might want to create different Content Types or file
        fields in existing ones and add some test content');
      $description .= "<br />";
      $description .= t('Interfaces fro this module:');
      $description .= "<ul>";
      $description .= "<li>";
      $description .= t('"/site-content" -> All website content.');
      $description .= "</li>";
      $description .= "<li>";
      $description .= t('"/site-content/select" -> Selected content that has files attached.');
      $description .= "</li>";
      $description .= "</ul>";return $description;
      break;
    case 'code_examples_reads':
      $description = t('This module allow users to mark a node as read.');
      $description .= "<br />";
      $description .= t('This module was developed for a use case where the Flag
        module was failing due to different combination of existing modules and custom code.');
      $description .= "<br />";
      $description .= t('This module contains different elements:');
      $description .= "<ul>";
      $description .= "<li>";
      $description .= t('Button on each Node page to mark node as Read/Unread.');
      $description .= "</li>";
      $description .= "<li>";
      $description .= t('Ajax functionality for the Read button.');
      $description .= "</li>";
      $description .= "<li>";
      $description .= t('Count reads interface by Node and by User entity. Local task tab on User and Node entities.');
      $description .= "</li>";
      $description .= "<li>";
      $description .= t('Export into CSV the Read count by User or Node.');
      $description .= "</li>";
      $description .= "</ul>";
      return $description;
      break;
    case 'code_examples_rest_integration':
      $description = t('This module is an example of a REST API integration.');
      $description .= "<br />";
      $description .= t('This example module is empty.');
      return $description;
      break;
    default:
      return '';
  }
}