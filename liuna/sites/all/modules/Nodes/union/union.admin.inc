<?php

/**
 * @file
 * Administration page callbacks for the Facebook module.
 *
 */

function union_admin_settings() {
	/* Rockets to =
	%s/\s'\(.*\)=> \(.*\)/$form['union_settings']['union_test']['\1'] = \2;/g
	 */

	$form['union_settings']['union_test']=array();
		$form['union_settings']['union_test']['#type']		= 'textfield';
		$form['union_settings']['union_test']['#required']	=  true;
		$form['union_settings']['union_test']['#title']		= 'Test Field';
		$form['union_settings']['union_test']['#description']	= ':P totally going to work';
		$form['union_settings']['union_test']['#default_value'] =  variable_get('union_test',':dance:');
		
		$form['#submit'][] = 'union_admin_settings_submit';
			return system_settings_form($form);
}

function union_admin_settings_submit($form,$form_state){

}

/* vim: set filetype=php : */
?>
