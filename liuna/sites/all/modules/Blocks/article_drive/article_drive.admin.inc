<?php
/**
 * @file
 * Administration page callbacks for the Article List Drive Box Block
 */

/**
 * Form builder to configure the Articles block
 *
 * @ingroup forms
 * @see system_settings_form()
 */
function article_drive_admin_settings() {
	$form['article_drive_block_settings']['article_drive_num_articles'] = array(
		'#title' => 'Number of Articles',
		'#type' => 'textfield',
		'#description' => 'How many articles should the block show?',
		'#required' => true,
		'#default_value' => variable_get('article_drive_num_articles', 5),
	);

	$form['#submit'][] = 'article_drive_admin_settings_submit';

	return system_settings_form($form);
}

/**
 * Submit handler for the Article Drive block configuration form
 *
 * @see variable_set()
 */
function article_drive_admin_settings_submit($form, $form_state) {
	variable_set('article_drive_num_articles', $form_state['values']['article_drive_num_articles']);
}

// vim: set ft=php :
?>
