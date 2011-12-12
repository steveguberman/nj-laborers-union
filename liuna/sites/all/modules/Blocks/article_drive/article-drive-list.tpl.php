<?php
/**
 * Article Drive Box List View
 *
 * Renders a list of 5 recent promoted articles into an unordered list w/ excerpts and links.
 *
 * Available Variables:
 * - $excerpts: An array of HTML strings, containing the article's title and a 255 character excerpt
 */
?>
<ul id="article-drive">
	<?php foreach($excerpts as $excerpt): ?>
		<li>
			<?php echo $excerpt; ?>
		</li>
	<?php endforeach; ?>
</ul>
