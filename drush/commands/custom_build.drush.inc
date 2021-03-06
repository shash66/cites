<?php
/**
 * @file
 * Implements some developer commands.
 */


/**
 * Implements hook_drush_command().
 */
function custom_build_drush_command() {
  $items = array();

  $items['custom_build'] = array(
    'description' => 'Runs database updates, reverts features and clears caches.',
    'callback' => '_drush_custom_build',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );

  return $items;
}

/**
 * Executes the build commands.
 */
function _drush_custom_build() {
  $modules = drush_get_option('init-modules', array());
  _drush_custom_enable_modules($modules);

  drush_invoke('updatedb');

  drush_invoke('cc', array('type' => 'all'));

  drush_invoke_process('@self', 'features-revert-all', array(), array(
    'force' => TRUE,
    'yes' => TRUE,
  ));
  drush_invoke('cc', array('type' => 'all'));
  drush_log(dt('Built!'), 'success');
}

function _drush_custom_enable_modules($modules) {
  if (empty($modules)) {
    return;
  }
  if (is_string($modules)) {
    $modules = explode(',', $modules);
  }
  foreach ($modules as $module) {
    if (!module_exists($module)) {
      if (!module_enable(array($module))) {
        drush_log(dt('Failed to enable @module', array('@module' => $module)), 'error');
      }
      else {
        drush_log("Enabling $module ...\n", 'ok');
      }
    }
  }
}
