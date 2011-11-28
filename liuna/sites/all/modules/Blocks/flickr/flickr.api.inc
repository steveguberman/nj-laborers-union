<?php
/**
 * Flickr API Access Library
 * by Mike Green
 */

class Flickr {
	public $api_key;
	public $curl;
	public $base_uri;

	/**
	 * Constructor Function
	 *
	 * Takes a Flickr API key and sets up an instance of the API client class
	 */
	public function __construct($api_key) {
		$this->base_uri = "http://api.flickr.com/services/rest?";
		$this->api_key = $api_key;
		$this->curl = curl_init();

		curl_setopt($this->curl, CURLOPT_RETURNTRANSFER, true);
		curl_setopt($this->curl, CURLOPT_USERAGENT, "Liuna-PHP-Flickr-Client-0.1");
	}

	/**
	 * Destructor function: closes the shared cURL handle
	 */
	public function __destruct() {
		curl_close($this->curl);
	}

	/**
	 * Get Favorites
	 *
	 * Calls flickr.favorites.getPublicList to get a user's public favorites list.
	 */
	public function get_favorites($user_id, $per_page=100, $page_num=1) {
		$url = $this->build_api_url(array(
			'method'   => 'flickr.favorites.getPublicList',
			'api_key'  => $this->api_key,
			'user_id'  => $user_id,
			'per_page' => $per_page,
			'page'     => $page_num,
			'format'   => 'php_serial',
		));

		curl_setopt($this->curl, CURLOPT_URL, $url);

		try {
			$faves = $this->fire_request();
			return $faves['photos'];
		} catch (Exception $e) {
			$this->log_error($e->getMessage());
			return false;
		}
	}

	/**
	 * Get tagged photos
	 *
	 * Calls flickr.photos.search and finds photos with the given tag
	 *
	 * $tags should be a string, a comma delimited list of tags or a single tag.
	 */
	public function get_tagged_photos($tags, $per_page=50, $page_num=1) {
		$url = $this->build_api_url(array(
			'method'   => 'flickr.photos.search',
			'tags'     => $tags,
			'page'     => $page_num,
			'per_page' => $per_page,
		));

		curl_setopt($this->curl, CURLOPT_URL, $url);

		try {
			$resp = $this->fire_request();
			return $resp['photos'];
		} catch (Exception $e) {
			$this->log_error($e->getMessage());
			return false;
		}
	}

	/**
	 * Get available sizes for a single photo
	 *
	 * Calls flickr.photos.getSizes on a single photo and returns array of available sizes
	 */
	public function get_sizes($photo_id) {
		$url = $this->build_api_url(array(
			'method' => 'flickr.photos.getSizes',
			'api_key' => $this->api_key,
			'photo_id' => $photo_id,
			'format' => 'php_serial',
		));

		curl_setopt($this->curl, CURLOPT_URL, $url);

		try {
			$sizes = $this->fire_request();
			return $sizes['sizes']['size'];
		} catch (Exception $e) {
			$this->log_error($e->getMessage());
			return false;
		}
	}

	/**
	 * Lookup Flickr user's NSID via the URL to their profile
	 *
	 * Calls flickr.urls.lookupUser and returns their NSID as a string
	 */
	public function lookup_user_id($url) {
		$url = $this->build_api_url(array(
			'method'  => 'flickr.urls.lookupUser',
			'api_key' => $this->api_key,
			'url'     => $url,
		));

		curl_setopt($this->curl, CURLOPT_URL, $url);

		try {
			$url = $this->fire_request();
			return $url['user']['id'];
		} catch (Exception $e) {
			$this->log_error($e->getMessage());
			return false;
		}
	}

	/**
	 * Log exception via pretty_r if available (private)
	 */
	private function log_error($msg) {
		if (function_exists('pretty_r')) {
			pretty_r($msg);
		}
		return null;
	}

	/**
	 * Build API URL (private)
	 *
	 * Takes an associative array and builds a Flickr API URL using the array as 
	 * query string parameters
	 */
	private function build_api_url($args=array()) {
		$uri = $this->base_uri;
		if (0 < count($args)) {
			foreach ($args as $key => $val) {
				$encoded_val = urlencode($val);
				$uri .= "{$key}={$encoded_val}&";
			}
		}
		return rtrim($uri, "&?");
	}

	/**
	 * Execute HTTP request and return unserialized response as array
	 */
	private function fire_request() {
		$raw_response = curl_exec($this->curl);
		
		if ($parsed_response = unserialize($raw_response)) {
			return $parsed_response;
		} else {
			throw new Exception('Flickr returned unprocessable response.');
		}
	}
}

// vim: set ft=php :
?>
