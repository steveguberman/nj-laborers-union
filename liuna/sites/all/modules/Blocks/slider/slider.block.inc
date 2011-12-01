<?php
/**
 * Slider block template preprocessing functions
 *
 * @see template_preprocess()
 */

function template_preprocess_slider_block_item(&$variables) {

}

function template_preprocess_slider_block_widget(&$variables) {
	$html_items = array();
	foreach ($variables['items'] as $item) {
		$html_items[] = theme('slider_block_item', array('item' => $item));
	}
	$variables['slides'] = $html_items;
}

// vim: set ft=php :
?>
