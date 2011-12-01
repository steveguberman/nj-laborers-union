<?php
/**
 * @file
 * Slider Block Item Template
 *
 * Available variables:
 * - $title: Title of the slide.
 * - $caption: A longer description of the slide.
 * - $title_encoded: Title with HTML entities encoded.
 * - $caption_encoded: Caption with HTML entities encoded.
 * - $src: URL of the slide's full-size image.
 * - $thumb: URL of the full-size image's thumbnail version.
 * - $href: URL that the slide should link to.
 */
?>
<li class="panel" data-title="<?php echo $title_encoded; ?>" data-caption="<?php echo $caption_encoded; ?>">
	<a href="<?php echo $href; ?>" class="slide-link">
		<img src="<?php echo $src; ?>" width="900" height="290" alt="<?php echo $title_encoded; ?>"/>
	</a>
	<div class="thumbnail" style="display: none;">
		<img src="<?php echo $thumb; ?>" width="200" height="100" alt="<?php echo $title_encoded; ?>" />
	</div>
</li>
