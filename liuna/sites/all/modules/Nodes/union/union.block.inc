<?php

function template_preprocess_union_info(&$variables){

$node = $variables['node'];
$node_language = $node->language;


$variables['info']['address']	= $node->union_address_field[$node_language][0]['safe_value'];
$variables['info']['type']	= $node->union_taxnav_vocabulary[$node_language][0]['taxonomy_term']->name;
$variables['info']['contact']	= $node->union_contact_field[$node_language][0]['safe_value'];
$variables['info']['website']	= $node->union_website[$node_language][0]['safe_value'];
}





// vim: set ft=php  :
?>
