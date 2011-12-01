<?php

/**
 * @file flickr-drive.admin.inc
 * Administration page callbacks for the Flickr block
 */

/**
 * Form builder to configure the Flickr block
 * @ingroup forms
 * @see system_settings_form()
 */
function flickr_drive_admin_settings() {
	$form['flickr_drive_block_settings']['flickr_drive_api_key'] = array(
		'#title'         => 'Flickr API Key',
		'#type'          => 'textfield',
		'#description'   => 'Enter your Flickr API Key',
		'#required'      => true,
		'#default_value' => variable_get('flickr_drive_api_key', '6dccccbedab9f442055f9d2a25ab6428'),
	);

	$form['flickr_drive_block_settings']['flickr_drive_num_photos'] = array(
		'#title'         => 'Number of Photos',
		'#type'          => 'textfield',
		'#description'   => 'The number of photos to display in the block',
		'#required'      => true,
		'#default_value' => variable_get('flickr_drive_num_photos', '2'),
	);

	$form['flickr_drive_block_settings']['flickr_drive_profile_url'] = array(
		'#title'         => 'Flickr Profile URL',
		'#type'          => 'textfield',
		'#description'   => 'The URL of your Flickr profile',
		'#required'      => true,
		'#default_value' => variable_get('flickr_drive_profile_url', 'http://www.flickr.com/photos/njlaborers/'),
	);

	$form['flickr_drive_block_settings']['flickr_drive_photo_tag'] = array(
		'#title'         => 'Photo tag',
		'#type'          => 'textfield',
		'#description'   => 'Display photos that have this tag',
		'#required'      => true,
		'#default_value' => variable_get('flickr_drive_photo_tag', 'njldrive'),
	);

	$form['#submit'][] = 'flickr_drive_admin_settings_submit';

	return system_settings_form($form);
}

function flickr_drive_admin_settings_submit($form, $form_state) {
	$flickr_path = drupal_get_path('module', 'flickr');
	require_once($flickr_path . '/flickr.api.inc');
	
	$api_key     = $form_state['values']['flickr_drive_api_key'];
	$profile_url = $form_state['values']['flickr_drive_profile_url'];
	$flickr      = new Flickr($api_key);
	$user_id     = $flickr->lookup_user_id($profile_url);

	variable_set('flickr_drive_api_key', $api_key);
	variable_set('flickr_drive_profile_url', $profile_url);
	variable_set('flickr_drive_num_photos', $form_state['values']['flickr_drive_num_photos']);
	variable_set('flickr_drive_user_nsid', $user_id);
}

// vim: set ft=php :
?>
