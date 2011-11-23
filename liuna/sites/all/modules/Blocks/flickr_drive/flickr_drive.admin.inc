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
		'#title' => 'Flickr API Key',
		'#type' => 'textfield',
		'#description' => 'Enter your Flickr API Key',
		'#required' => true,
		'#default_value' => variable_get('flickr_drive_api_key', '6dccccbedab9f442055f9d2a25ab6428'),
	);

	$form['flickr_drive_block_settings']['flickr_drive_num_photos'] = array(
		'#title' => 'Number of Photos',
		'#type' => 'textfield',
		'#description' => 'The number of photos to display in the block',
		'#required' => true,
		'#default_value' => variable_get('flickr_num_photos', '2'),
	);

	$form['#submit'][] = 'flickr_drive_admin_settings_submit';

	pretty_r($form);
	return system_settings_form($form);
}

function flickr_drive_admin_settings_submit($form, $form_state) {
	variable_set('flickr_drive_api_key', $form_state['values']['flickr_drive_api_key']);
	variable_set('flickr_drive_num_photos', $form_state['values']['flickr_drive_num_photos']);
}

// vim: set ft=php :
?>
