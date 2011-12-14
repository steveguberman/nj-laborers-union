<?php
/**
 * @file
 * AnythingSlider Admin Settings
 */

/**
 * Form builder to configure the Slider block
 *
 * @ingroup forms
 * @see system_settings_form()
 */
function slider_admin_settings() {
	$easing_formulae = array(
		'linear', 'swing', 'jswing', 'easeInQuad', 'easeOutQuad', 'easeInOutQuad',
		'easeInCubic', 'easeOutCubic', 'easeInOutCubic', 'easeInQuart', 'easeOutQuart',
		'easeInOutQuart', 'easeInQuint', 'easeOutQuint', 'easeInOutQuint', 'easeInSine',
		'easeOutSine', 'easeInOutSine', 'easeInExpo', 'easeOutExpo', 'easeInOutExpo',
		'easeInCirc', 'easeOutCirc', 'easeInOutCirc', 'easeInElastic', 'easeOutElastic',
		'easeInOutElastic', 'easeInBack', 'easeOutBack', 'easeInOutBack', 'easeInBounce',
		'easeOutBounce', 'easeInOutBounce',
	);
	$easing_opts = drupal_map_assoc($easing_formulae);

	$form['slider_block_settings']['slider_animation_easing'] = array(
		'#title'         => 'Animation Easing',
		'#type'          => 'select',
		'#default_value' => variable_get('slider_animation_easing', 'easeInQuad'),
		'#options'       => $easing_opts,
		'#description'   => t('Easing function for slider animation'),
		'#required'      => false,
	);

	$form['slider_block_settings']['slider_animation_speed'] = array(
		'#title'         => 'Animation Speed',
		'#type'          => 'textfield',
		'#default_value' => variable_get('slider_animation_speed', 400),
		'#description'   => 'Animation speed, in milliseconds, of the slider.',
		'#required'      => true,
	);

	$form['slider_block_settings']['slider_transition_interval'] = array(
		'#title'         => 'Transition Interval',
		'#type'          => 'textfield',
		'#default_value' => variable_get('slider_transition_interval', 10),
		'#description'   => 'The amount of time between transitions (in seconds)',
		'#required'      => true,
	);

	return system_settings_form($form);
}

/**
 * Slider block settings form submit handler
 */
function slider_admin_settings_submit($form, $form_state) {
	variable_set('slider_animation_easing', $form_state['values']['slider_animation_easing']);
	variable_set('slider_animation_speed', $form_state['values']['slider_animation_speed']);
	variable_set('slider_transition_interval', $form_state['values']['slider_transition_interval']);
}

// vim: set ft=php :
?>
