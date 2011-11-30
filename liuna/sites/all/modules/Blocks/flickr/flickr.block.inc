<?php

function template_preprocess_flickr_thumbnail_grid(&$variables) {
	$photos = array();
	$flickr = new Flickr($variables['api_key']);

	// For each photo, grab the "small" size version and replace its URL attribute with the Original size's URL
	foreach ($variables['items'] as $photo) {
		if (!isset($photo['id'])) continue;
		$data = @$flickr->get_sizes($photo['id']);
		$thumb = $data[2];
		$thumb['url'] = $data[count($data)-1]['url'];
		$thumb['class'] = ($thumb['width'] > $thumb['height']) ? "landscape" : "portrait";
		$photos[] = $thumb;
	}
	$variables['photos'] = $photos;
}

//vim: set ft=php :
?>
