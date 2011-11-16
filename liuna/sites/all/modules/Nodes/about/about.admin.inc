<?php

/**
 * @file
 * Administration page callbacks for the Facebook module.
 *
 */

/**
 * Form builder. Configure Facebook authentification.
 * @ingroup forms
 * @see system_settings_form().
 */

function about_admin_settings() {

	$form['about_settings']['about_test']=array(
	'#type' 	=> 'textfield',
	'#required'	=> true,
	'#title'	=> 'Test Field',
	'#description'	=> ':P totally going to work',
	'#default_value'=> variable_get('about_test',':dance:'),
	);

	$form['#submit'][] = 'about_admin_settings_submit';

	return system_settings_form($form);
}

function facebook_admin_settings_submit($form,$form_state){
	variable_set('fb_url',$form_state['values']['about_test']);
}

/* vim: set filetype=php : */
?>
