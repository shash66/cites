<?php
/**
 * @file
 * slideshow.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function slideshow_user_default_permissions() {
  $permissions = array();

  // Exported permission: access content.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: create slide content.
  $permissions['create slide content'] = array(
    'name' => 'create slide content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any slide content.
  $permissions['delete any slide content'] = array(
    'name' => 'delete any slide content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own slide content.
  $permissions['delete own slide content'] = array(
    'name' => 'delete own slide content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any slide content.
  $permissions['edit any slide content'] = array(
    'name' => 'edit any slide content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own slide content.
  $permissions['edit own slide content'] = array(
    'name' => 'edit own slide content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
