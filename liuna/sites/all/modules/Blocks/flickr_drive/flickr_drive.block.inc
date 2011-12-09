<?php
/**
 * Flickr Drive Box Preprocessing Hooks
 */

function template_preprocess_flickr_drive_thumbnail_list(&$variables) {
	$photos = array();
	$flickr = new Flickr($variables['api_key']);

	foreach ($variables['items'] as $photo) {
		if (!isset($photo['id'])) continue;

		$data = @$flickr->get_sizes($photo['id']);
		$thumb = $data[2];
		$thumb['url'] = $data[count($data) - 1]['url'];
		$thumb['class'] = ($thumb['width'] > $thumb['height']) ? "landscape" : "portrait";
		$thumb['width'] = $thumb['width'] / 2;
		$thumb['height'] = $thumb['height'] / 2;
		$photos[] = $thumb;
	}

	$variables['photos'] = $photos;
}

// vim: set ft=php :
?>
