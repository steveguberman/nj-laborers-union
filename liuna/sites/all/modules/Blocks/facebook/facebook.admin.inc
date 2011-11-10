<?php

/**
 * @file
 * Administration page callbacks for the Facebook module.
 *
 */

/**
 * Form builder. Configure Facebook widget.
 * @ingroup forms
 * @see system_settings_form().
 */

function facebook_admin_settings() {

	$form['facebook_widget_settings']['fb_url']=array(
	'#title'	=> 'Facebook URL',
	'#type' 	=> 'textfield',
	'#description'	=> 'Enter Url to the Facebook acount you would like to use.',
	'#required'	=> true,
	'#default_value'=> variable_get('fb_url','http://www.facebook.com/pages/LiUNA-Eastern-Region/224388557595313'),
	);
	
	$form['facebook_widget_settings']['fb_show_face']=array(
	'#title'	=> 'Widget Options',
	'#type' 	=> 'checkboxes',
	'#description'	=> 'Would you like to show faces on the widget?',
	'#required'	=> true,
	'#options'	=> array('True'=>'yes'),
	'#default_value'=> variable_get('fb_show_face',array('True'=>'yes')),
	);
	
	$form['#submit'][] = 'facebook_admin_settings_submit';

	pretty_r($form);

	return system_settings_form($form);
}

function facebook_admin_settings_submit($form,$form_state){
	variable_set('fb_url',$form_state['values']['fb_url']);
	variable_set('fb_show_face',$form_state['values']['fb_show_face']);
}


/* vim: set filetype=php : */
?>
