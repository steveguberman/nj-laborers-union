<?php



//taxonomoy_get_tree($vid);
//taxonomy_select_nodes($term);
//node_load($nid);
//menu_delete($machine_name);


// function that builds a navigation based on a taxonomy vocabulary instance
function build(){
	drupal_set_message('Building TaxNav Menu Tree');

$processing=array();

	$taxonomy_tree=taxonomy_get_tree(variable_get('taxnav_vocabulary'));

	$tree=array();
		foreach($taxonomy_tree as $term){
			$working_tid=$term->tid;
				$tree[$working_tid]=array();
					$tree[$working_tid]['name']=$term->name;
					$tree[$working_tid]['parent_list']=array();
					$tree[$working_tid]['children']=(taxonomy_get_children($working_tid))?true:false;
	
					$parents_temp=taxonomy_get_parents_all($working_tid);
						array_shift($parents_temp);
						foreach($parents_temp as $parent){
						$tree[$working_tid]['parent_list'][]=$parent->tid;
						}
					$tree[$working_tid]['nodes']=array();
						foreach( taxonomy_select_nodes($working_tid) as $node){
						$tree[$working_tid]['nodes'][$node]=node_load($node)->title;
						}
		}
	
	dpm($tree,'Menu tree');

	drupal_set_message('Removing Old Menu Tree');
	$result = db_query("SELECT * FROM menu_custom WHERE menu_name=:menu_name", array( 'menu_name'=> variable_get('taxnav_menu') ) );
	menu_delete($result->fetchAssoc());

	drupal_set_message('Creating New  Menu Tree');
	$new_menu = array();
		$new_menu['menu_name']		= 'taxnav_menu';
		$new_menu['title']		= 'Taxnav menu';
		$new_menu['description']	= 'Menu based on taxnav module taxonomy tagging system';
	
		menu_save($new_menu);

	drupal_set_message('Populating Menu Tree');

	
	dpm($tree,'tree');


	foreach($tree as $tid => $leaf){
	drupal_set_message('Creating Leaf');
	dpm($leaf);

		$plid=0;
			if($leaf['parent_list']){
				
			$parent_id = $leaf['parent_list'][sizeof($leaf['parent_list'])-1];
				dpm($parent_id,'Parent Id');

			$plid= $tree[$parent_id]['lid'];
			}
	
	$taxnav_page=_taxnav_page_from_tid($tid);

			$item=array();
				$item['link_path']	= drupal_get_normal_path("node/$taxnav_page->nid");
				$item['link_title']	= '__'.$leaf['name'];
				$item['menu_name']	= variable_get('taxnav_menu');			
				$item['plid']		= $plid;
											// This has to break the laws of the programming universe
					$leaf['lid'] = menu_link_save($item);
					$tree[$tid] = $leaf;

	drupal_set_message('Adding nodes to leaf');
		if($leaf['nodes']){
			foreach($leaf['nodes'] as $id => $node){
			$item=array();
				$item['link_path']	= drupal_get_normal_path("node/$id");
				$item['link_title']	= $node;
				$item['menu_name']	= variable_get('taxnav_menu');
				$item['plid']		= $tree[$tid]['lid'];  // <--- here we pull the raptor from the hat
				dpm($item,'Menu Entry');
				dpm(menu_link_save($item),'SPOOT');
			}
		}

	}
	drupal_set_message('TaxNav Menu Built');
	
	
}

/*vim : set filetype=php : */
?>
