<?php
/**
 * Article Drive Box List Item
 *
 * Renders a single drive box list item for an article.
 *
 * Available Variables:
 * - $article: Database representation of an article
 * - $title: Title of the article
 * - $href: The article's URL
 * - $excerpt: A 255 character excerpt of the article's body
 */
?>
<strong><a href="<?php echo $href; ?>"><?php echo $title; ?></a></strong>
