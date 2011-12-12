<?php
/**
 * Article Drive Box Template Preprocessors
 */

function template_preprocess_article_drive_box_list(&$variables) {
	$excerpts = array();

	foreach ($variables['items'] as $item) {
		$excerpts[] = theme('article_drive_list_item', array('item' => $item));
	}

	$variables['excerpts'] = $excerpts;
}

function template_preprocess_article_drive_box_list_item(&$variables) {
	$node = $variables['item'];
	$article = node_load($node->nid);
	$language = $article['language'];
	$summary = $article['body'][$language][0]['summary'];

	// Bind template variables:
	$variables['article'] = $article;
	$variables['title']   = $article['title'];
	$variables['href']    = "/nodes/{$article['nid']}";
	$variables['excerpt'] = truncate_string($summary, 255, ' ');
}

// Utility Function: Truncate String
function truncate_string($string, $limit, $break=".", $pad="...") { 
	// return with no change if string is shorter than $limit  
	if(strlen($string) <= $limit) return $string; 

	// is $break present between $limit and the end of the string?  
	if(false !== ($breakpoint = strpos($string, $break, $limit))) { 
		if($breakpoint < strlen($string) - 1) { 
			$string = substr($string, 0, $breakpoint) . $pad; 
		} 
	}
	return $string; 
}

// vim: set ft=php :
?>
