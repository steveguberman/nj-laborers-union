<?php



function template_preprocess_articles_list(&$variables){
	

	$articles_out = array();
	foreach($variables['articles'] as $article){
		$articles_out[] = node_view($article);
	}
	
	$variables['articles'] = $articles_out;
	
}



// vim: set ft=php :

?>
