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
<li data-title="<?php echo $title_encoded; ?>" data-caption="<?php echo $caption_encoded; ?>" data-thumb="<?php echo $thumb; ?>">
	<a href="<?php echo $href; ?>" class="slide-link">
		<img src="<?php echo $src; ?>" width="900" height="290" alt="<?php echo $title_encoded; ?>"/>
		<p class="caption">
			<?php echo $title; ?>
		</p>
	</a>
</li>
