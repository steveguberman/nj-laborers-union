<?php
ini_set('display_errors', 1); 
error_reporting(E_ALL);

if(!function_exists('xdebug_break')){
	function xdebug_break(){
	trigger_error('REMOVE Debug functions from script!',E_WARNING);
	}
}

//ini_set('error_log', dirname(__FILE__) . '/error_log.txt'); 

/**
 * @file
 * The PHP page that serves all page requests on a Drupal installation.
 *
 * The routines here dispatch control to the appropriate handler, which then
 * prints the appropriate page.
 *
 * All Drupal code is released under the GNU General Public License.
 * See COPYRIGHT.txt and LICENSE.txt.
 */

/**
 * Root directory of Drupal installation.
 */
define('DRUPAL_ROOT', getcwd());

require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

//break here to have a fully loaded Drupal instance to run live commands from the debugger on.
xdebug_break();

menu_execute_active_handler();
