/**
 * @file
 * JavaScript file defining Overlay behaviour.
 */

(function ($) {

  // Default behaviour after submit the Form.
  Drupal.ajax.prototype.commands.closeColorbox = function(ajax, response, status) {
    $("td input:checked").each(function (i) {
      $(this).removeAttr("checked");
    });
    $('#cboxClose').click();
  };

  // Open Overlay in Colorbox Node
  Drupal.ajax.prototype.commands.selectedContent = function(ajax, response, status) {
    $('<a href="' + response.selectedLink + '"></a>').colorboxNode({width: '80%'});
  };

  // Download the link
  Drupal.ajax.prototype.commands.downloadFiles = function(ajax, response, status) {
    window.location.href = response.downloadLink;
  };


})(jQuery);