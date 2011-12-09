<?php
/**
 * Slider block template preprocessing functions
 *
 * @see template_preprocess()
 */

/**
 * Preprocess and bind variables for single slider items
 *
 * @see slider-block-item.tpl.php
 */
function template_preprocess_slider_block_item(&$variables) {
	$slide                = $variables['item'];
	$variables['title']   = $slide['title'];
	$variables['caption'] = $slide['caption'];
	$variables['src']     = $slide['src'];
	$variables['thumb']   = $slide['thumb'];
	$variables['href']    = $slide['href'];
	$variables['title_encoded'] = htmlspecialchars($variables['title']);
	$variables['caption_encoded'] = htmlspecialchars($variables['caption']);
}

/**
 * Assemble individual slides into an array of HTML snippets for the main slider template.
 *
 * @see slider-block-widget.tpl.php
 */
function template_preprocess_slider_block_widget(&$variables) {
	$html_items = array();
	foreach ($variables['items'] as $item) {
		$html_items[] = theme('slider_block_item', array('item' => $item));
	}
	$variables['slides'] = $html_items;
}

// vim: set ft=php :
?>
