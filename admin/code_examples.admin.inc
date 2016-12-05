<?php

/**
 * @file
 * Administration interface for Code Examples module.
 */

/**
 * Page callback with the content of the Administration interface.
 * @return mixed
 */
function code_examples_page() {

  $content['content'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => 'ce-module ce-module-admin'),
  );

  $content['content']['title'] = array(
    '#type' => 'markup',
    '#markup' => t('Help Page for Code Examples'),
    '#prefix' => '<h2 class="ce-title">',
    '#suffix' => '</h2>',
  );

  $content['content']['header'] = array(
    '#type' => 'markup',
    '#markup' => t('This module is a recompilation of different code examples
        from existing projects I have been working on. The examples were ported
        and adapted and some of them modified or even changed the original purpose
        to have some code to show on the interview process. Please do not hesitate
        to contact me if there is any questions about these examples in
        info@luisrc.gal. <br /> I have added inline comments to the code, all
        the examples are under the "modules" subdirectory in this main module.
        <br /> Please note some of the examples are not using proper
        implementations, this is due to the time I have, I have used hook_node_view
        to display some output elements that should be done with other methods.'),
    '#prefix' => '<p class="ce-desc">',
    '#suffix' => '</p>',
  );

  if ($sub_modules = ce_get_submodules()) {
    $content['content']['submodules'] = array(
      '#type' => 'container',
      '#attributes' => array('class' => 'ce-sub-modules'),
    );
    foreach ($sub_modules as $key => $sub_module_name) {

      $content['content']['submodules'][$sub_module_name] = array(
        '#type' => 'markup',
        '#markup' => t('<h3>@submoduleTitle</h3><p>!submoduleDesc</p>',
          array(
            '@submoduleTitle' => $sub_module_name,
            '!submoduleDesc' => ce_submoduce_description($sub_module_name),
          )
        ),
        '#prefix' => '<div class="ce-sub-module">',
        '#suffix' => '</div>',
      );
    }
  }

  return $content;
}
