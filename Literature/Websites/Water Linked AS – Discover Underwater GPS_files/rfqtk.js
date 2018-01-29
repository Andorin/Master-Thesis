
function gpls_woo_rfq_plus_is_Decimal(evt){
    var charCode = (evt.which) ? evt.which : event.keyCode
    if (charCode > 31 && (charCode != 46 &&(charCode < 48 || charCode > 57)))
        return false;
    return true;
}

function gpls_woo_rfq_plus_is_Integer(evt){
    var charCode = (evt.which) ? evt.which : event.keyCode
    if (charCode > 31 && (charCode < 48 || charCode > 57))
        return false;
    return true;
}



jQuery(window).load(function() {


    jQuery('.gpls-woo-rfq_checkout_button').on('click', function(){

    });


    jQuery('.update_rfq_cart').on('click', function(){
        jQuery('#rfq_phone').removeClass("required");
        jQuery('#rfq_phone').attr("required",false);

        jQuery('#rfq_company').removeClass("required");
        jQuery('#rfq_company').attr("required",false);

        jQuery('#rfq_billing_country').removeClass("required");
        jQuery('#rfq_billing_country').attr("required",false);

        jQuery('#rfq_state_select').removeClass("required");
        jQuery('#rfq_state_select').attr("required",false);

        jQuery('#rfq_address').removeClass("required");
        jQuery('#rfq_address').attr("required",false);

        jQuery('#rfq_city').removeClass("required");
        jQuery('#rfq_city').attr("required",false);

        jQuery('#rfq_zip').removeClass("required");
        jQuery('#rfq_zip').attr("required",false);

        jQuery('#rfq_message').removeClass("required");
        jQuery('#rfq_message').attr("required",false);
    });


    jQuery('.accept_offer').on('change', function(){

        if(this.checked) {
            jQuery('#gpls_woo_rfq_accept_offer_submit').show();
        }else{
            jQuery('#gpls_woo_rfq_accept_offer_submit').hide();
        }


    });

    if(jQuery('.accept_offer').checked) {
        jQuery('#gpls_woo_rfq_accept_offer_submit').show();
    }else{
        jQuery('#gpls_woo_rfq_accept_offer_submit').hide();
    }




    jQuery('#gpls_woo_rfq_accept_offer_submit').on('click', function(){

        jQuery('#gpls_woo_rfq_customer_note').attr("required",false);
      //  jQuery('.gpls_woo_rfq_customer_note').rules('remove');


    });

    jQuery('#gpls_woo_rfq_customer_note_submit').on('click', function(){


        jQuery(".gpls_woo_rfq_Plus_customer_note_form").validate();


    });

      jQuery('#gpls_woo_rfq_customer_note').attr("required",true);

    // jQuery("#gpls_woo_rfq_Plus_customer_note_form").validate();


    //jQuery('form.checkout').removeAttr( 'novalidate');


 //jQuery('#gpls_woo_rfq_plus_customer_bid').attr("required",false);




//jQuery('.woocommerce-OrderUpdates').hide();



} ); // jQuery( document ).ready
