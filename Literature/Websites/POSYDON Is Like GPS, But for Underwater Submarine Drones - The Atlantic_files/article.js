!function(){var articleHeight=$("#article .article-body section").last().height(),belowHeights=$("#article .module-authors").outerHeight()+$("#article .module-related").outerHeight()+350;articleHeight<belowHeights&&($("body").addClass("article-below-conflicts"),$("#ad-boxbottom").remove()),$(".article-tools a[data-toggles]").on("click",function(e){e.preventDefault(),$($(this).data("toggles")).toggleClass("active"),$(this).toggleClass("active")}),$(".authors-about a").on("click",function(){$(".module-authors").toggleClass("active")}),$(".footnote__link, .footnote__return-link").on("click",function(){var $this=$(this),id=$this.attr("id"),href=$this.attr("href"),navHeight=$("#site-header-container").height(),$footnote=$(href),top=$footnote.offset().top,OFFSET=16;return $window.scrollTop(top-navHeight-OFFSET),$this.hasClass(".footnote__link")&&$footnote.find(".footnote__return-link").attr("href","#"+id),!1});var $window=($(".article-above .social-kit-top"),$("footer"),$(window));Atlantic.User.isAdFree()&&$(".boxtop-most-popular").addClass("boxtop-most-popular--active")}(),window.Atlantic=window.Atlantic||{},Atlantic.AdSlider=function(options){this.$el=options.$el,this.pos=options.pos,this.threshold=options.threshold,this.bindEvents()},Atlantic.AdSlider.prototype.bindEvents=function(){this.$el.on("click",".close",this.hide.bind(this)),this._interval=setInterval(this.checkPosition.bind(this),1e3)},Atlantic.AdSlider.prototype.loadAd=function(){var googletag=window.googletag=window.googletag||{};googletag.cmd=googletag.cmd||[];var self=this;googletag.cmd.push(function(){Atlantic.Ad.sizeListener(self.pos,function($ad,size){size&&self.show()});var ad=self.$el.find("gpt-ad")[0];if(ad&&(ad.called=!0,googletag.pubads().refresh([ad.adSlot],{changeCorrelator:!1}),void 0!==typeof s_gi)){var layout=$("body").hasClass("article-full")?"full":$("body").hasClass("article-wide")?"wide":"standard",s=s_gi(window.s.account);s.events="event1",s.tl(!0,"o","serveslider`"+layout)}})},Atlantic.AdSlider.prototype.hide=function(e){this.$el.removeClass("open"),e.stopPropagation(),e.preventDefault()},Atlantic.AdSlider.prototype.show=function(){this.$el.addClass("open")},Atlantic.AdSlider.prototype.checkPosition=function(){window.pageYOffset>this.threshold&&(window.location.search.match(/debug_native/)?this.show():this.loadAd(),clearInterval(this._interval))},$(document).on("ready",function(){var $el=$(".native-promo-slider");$el.find("gpt-ad").attr("targeting-pos");Atlantic.adslider=new Atlantic.AdSlider({$el:$el,pos:"native-slider",threshold:$("#article").height()/2})}),function(){function encodeString(str){return str.replace('"',"'").replace("'","&#x27;")}function insertShareButtons(iframe){try{var $iframeDocument=$(iframe.contentDocument)}catch(e){return}var original_url=$iframeDocument.find('meta[property="og:url"]').eq(0).attr("content"),title=$iframeDocument.find('meta[property="og:title"]').eq(0).attr("content"),re_parts=RegExp("theatlantic.com/video/index/(\\d+?)/").exec(original_url),video_id=Boolean(re_parts)?re_parts[1]:void 0;if(original_url&&title&&video_id){var template=_.template($("#video-social-links-template").text()),social_links_string=template({original_url:encodeString(original_url),title:encodeString(title),escaped_title:encodeURIComponent(title),video_id:video_id}).trim(),$social_links=$($.parseHTML(social_links_string)),$wrapper=$(iframe).closest(".embed-wrapper"),$figure=$wrapper.parent("figure");$figure.addClass("has-sharebuttons"),$figure.append($social_links),$figure.has("figcaption").addClass("has-caption")}}var $iframes=$('#article figure iframe[src*="/video/iframe/"], #article figure iframe[data-src*="/video/iframe/"]');$iframes.each(function(index,iframe){iframe.src?insertShareButtons(iframe):iframe.hasAttribute("data-src")&&$(iframe).on("load",function(){insertShareButtons(this)})})}(),$(document).on("ready",function(){$.each($("[data-interactive-script]"),function(i,el){var url=el.getAttribute("data-interactive-script");$.getScript(url,function(el,url){var callback=el.getAttribute("data-callback");callback&&eval(callback)(el,url)}.bind(null,el,url))})}),function(){function setProportion($chart){var height,data=$chart.data().wrapperHeights,$responsiveWrapper=$chart.parent(".embed-wrapper");if($.isPlainObject(data)){data=_.map(data,function(value,key){return key=parseInt(key,10),[key,value]}),data=data.sort(function(a,b){return a[0]>b[0]});for(var height=$chart.height(),width=$chart.width(),i=data.length-1;i>=0&&!(width>data[i][0]);i--)height=data[i][1];if($responsiveWrapper.length){var proportion=height/width*100+"%";$responsiveWrapper.css({paddingBottom:proportion})}else $chart.css({height:height})}}for(var $charts=$("iframe[data-wrapper-heights]"),i=$charts.length-1;i>=0;i--)setProportion($charts.eq(i))}();var TextResizer={init:function(){if(this.$el=$(".article-body"),this.$el.length){var savedSize=Atlantic.Utils.readCookie("article-body-font-size");savedSize?(this.size=parseInt(savedSize,10),this.$el.css("font-size",this.size+"px")):(this.size=this.calculateCurrentFontSize(),Atlantic.Utils.createCookie("article-body-font-size",this.size,365)),this.bindEvents()}},calculateCurrentFontSize:function(){var $tmp=$('<div style="position:absolute;top:-1000px;left:-1000px;height:1em"></div>'),height=$tmp.appendTo(this.$el).height();return $tmp.remove(),height},bindEvents:function(){var self=this;$(".minus").click(function(){self.setSize(self.size-2)}),$(".plus").click(function(){self.setSize(self.size+2)})},setSize:function(value){value>=36||value<=12||(this.size=value,this.$el.css({"font-size":value+"px"}),Atlantic.Utils.createCookie("article-body-font-size",this.size,365))}};TextResizer.init();

//# sourceMappingURL=article.min.js.5c252426e64f.map