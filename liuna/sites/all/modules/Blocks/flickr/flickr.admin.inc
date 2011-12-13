<?php

/**
 * @file flicker.admin.inc
 * Administration page callbacks for the Flickr block
 */

/**
 * Form builder to configure the Flickr block
 * @ingroup forms
 * @see system_settings_form()
 */
function flickr_admin_settings() {
	$form['flickr_block_settings']['flickr_feed_url'] = array(
		'#title' => 'Flickr Feed URL',
		'#type' => 'textfield',
		'#description' => 'Enter URL to Flickr feed you want to display.',
		'#required' => true,
		'#default_value' => variable_get('flickr_feed_url', 'http://api.flickr.com/services/feeds/photos_faves.gne?nsid=62751423@N00&lang=en-us&format=php_serial'),
	);

	$form['flickr_block_settings']['flickr_api_key'] = array(
		'#title' => 'Flickr API Key',
		'#type' => 'textfield',
		'#description' => 'Enter your Flickr API key',
		'#required' => true,
		'#default_value' => variable_get('flickr_api_key', '6dccccbedab9f442055f9d2a25ab6428'),
	);

	$form['flickr_block_settings']['flickr_profile_url'] = array(
		'#title' => 'Flickr Profile URL',
		'#type' => 'textfield',
		'#description' => 'Enter the full URL to your Flickr profile page',
		'#required' => true,
		'#default_value' => variable_get('flickr_profile_url', 'http://www.flickr.com/photos/njlaborers/'),
	);

	$photo_sources = drupal_map_assoc(array('favorites', 'stream'));
	$form['flickr_block_settings']['flickr_photo_source'] = array(
		'#title'         => 'Photo Source',
		'#description'   => 'Show photos from favorites or photo stream?',
		'#type'          => 'select',
		'#default_value' => variable_get('flickr_photo_source', 'favorites'),
		'#options'       => $photo_sources,
	);

	$form['flickr_block_settings']['flickr_num_photos'] = array(
		'#title' => 'Number of Photos',
		'#type' => 'textfield',
		'#description' => 'The number of photos to display in the block',
		'#required' => true,
		'#default_value' => variable_get('flickr_num_photos', '16'),
	);

	$form['#submit'][] = 'flickr_admin_settings_submit';

	return system_settings_form($form);
}

function flickr_admin_settings_submit($form, $form_state) {
	$flickr_path = drupal_get_path('module', 'flickr');
	require_once($flickr_path . '/flickr.api.inc');

	$profile_url = urlencode($form_state['values']['flickr_profile_url']);
	$api_key     = urlencode($form_state['values']['flickr_api_key']);
	$flickr      = new Flickr($api_key);
	$user_id     = $flickr->lookup_user_id($profile_url);

	variable_set('flickr_user_nsid', $user_id);
	variable_set('flickr_feed_url', $form_state['values']['flickr_feed_url']);
	variable_set('flickr_num_photos', $form_state['values']['flickr_num_photos']);
	variable_set('flickr_api_key', $form_state['values']['flickr_api_key']);
	variable_set('flickr_profile_url', $form_state['values']['flickr_profile_url']);
	variable_set('flickr_photo_source', $form_state['values']['flickr_photo_source']);

	// Clear cached block content
	cache_clear_all('flickr_thumbnail_grid', 'cache_block');
}

// vim: set ft=php :
?>
