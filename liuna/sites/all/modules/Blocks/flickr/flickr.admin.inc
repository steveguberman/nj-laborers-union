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
		'#required' => true
		'#default_value' => variable_get('flickr_feed_url', 'http://api.flickr.com/services/feeds/photos_faves.gne?id=njlaborers&format=php'),
	);

	$form['flickr_block_settings']['flickr_num_photos'] = array(
		'#title' => 'Number of Photos',
		'#type' => 'textfield',
		'#description' => 'The number of photos to display in the block',
		'#required' => true,
		'#default_value' => variable_get('flickr_num_photos', '16'),
	);

	$form['#submit'][] = 'flickr_admin_settings_submit';

	pretty_r($form);
	return system_settings_form($form);
}

function flickr_admin_settings_submit($form, $form_state) {
	variable_set('flickr_feed_url', $form_state['values']['flickr_feed_url']);
	variable_set('flickr_num_photos', $form_state['values']['flickr_num_photos']);
}

// vim: set ft=php :
?>
