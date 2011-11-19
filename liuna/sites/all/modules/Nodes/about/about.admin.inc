<?php

/**
 * @file
 * Administration page callbacks for the Facebook module.
 *
 */

function about_admin_settings() {
	/* Rockets to =
	%s/\s'\(.*\)=> \(.*\)/$form['about_settings']['about_test']['\1'] = \2;/g
	 */

	$form['about_settings']['about_test']=array();
		$form['about_settings']['about_test']['#type']		= 'textfield';
		$form['about_settings']['about_test']['#required']	=  true;
		$form['about_settings']['about_test']['#title']		= 'Test Field';
		$form['about_settings']['about_test']['#description']	= ':P totally going to work';
		$form['about_settings']['about_test']['#default_value'] =  variable_get('about_test',':dance:');
		
		$form['#submit'][] = 'about_admin_settings_submit';
			return system_settings_form($form);
}

function about_admin_settings_submit($form,$form_state){

}

/* vim: set filetype=php : */
?>
