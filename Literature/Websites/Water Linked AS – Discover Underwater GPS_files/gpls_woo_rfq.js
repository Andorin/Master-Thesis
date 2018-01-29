

jQuery( document ).ready( function() {

    jQuery('form.checkout').removeAttr( 'novalidate');
    jQuery('.required').attr("required",true);


    jQuery('.gpls-woo-rfq_update-rfq-cart_button').on('click', function(){

        jQuery('input[name="gpls-woo-rfq_update"]' ).val(true);
        jQuery('input[name="gpls-woo-rfq_checkout"]' ).val(false);

        //jQuery("#rfqform").rules('remove');

        jQuery('#rfq_fname').attr("required", false);
        jQuery('#rfq_lname').attr("required", false);
        jQuery('#rfq_email_customer').attr("required", false);

        jQuery('#rfq_fname').removeClass("required");
        jQuery('#rfq_lname').removeClass("required");
        jQuery('#rfq_email_customer').removeClass("required");

      /*  jQuery("#rfqform").validate(

        function() {
            jQuery("#rfqform").rules('remove');
            jQuery('#rfq_fname').attr("required", false);
            jQuery('#rfq_lname').attr("required", false);
            jQuery('#rfq_email_customer').attr("required", false);

            jQuery('#rfq_fname').removeClass("required");
            jQuery('#rfq_lname').removeClass("required");
            jQuery('#rfq_email_customer').removeClass("required");

            //jQuery('.qty').rules('remove');
        }

        );*/

    });


    jQuery('.gpls-woo-rfq_checkout_button').on('click', function(){

        jQuery('.required').attr("required",true);

        jQuery('#rfq_fname').attr("required",true);
        jQuery('#rfq_lname').attr("required",true);
        jQuery('#rfq_email_customer').attr("required",true);

        jQuery('input[name="gpls-woo-rfq_update"]' ).val(false);
        jQuery('input[name="gpls-woo-rfq_checkout"]' ).val(true);


       /* jQuery("#rfqform").validate({
            ignore: ".cart_td .qty"
        }
            ,
            function(){
               // jQuery("#rfqform").rules('remove');
               // jQuery('.cart_td table.cart_td .quantity .qty').rules('remove');
              //  jQuery('.qty').rules('remove');
             //   jQuery('.cart_td .qty').rules('remove');


                jQuery('#rfq_fname').addClass("required");
                jQuery('#rfq_lname').addClass("required");
                jQuery('#rfq_email_customer').addClass("required");

                jQuery('.required').rules("add", {required:true});

                jQuery('.rfq_cart_shop_table .qty').rules('remove');

            }


        );*/





    });

    jQuery('.rfq_billing_country').on('change', function(){


        if( jQuery('#rfq_billing_country').val() !='US'){
            jQuery('#rfq_state_select').val("");
            jQuery('#rfq_state_select').hide();
            jQuery('#rfq_state_text').show();
        }else{
            jQuery('#rfq_state_text').val("");
            jQuery('#rfq_state_text').hide();
            jQuery('#rfq_state_select').show();

        }

    });


    jQuery('.gpls_rfq_set').on('click', function(){
        var variation_id=jQuery("[name='variation_id']").val();
        var rfq_product_id=jQuery("[name='add-to-cart']").val();

        jQuery("[name='rfq_product_id']").val(1);
        jQuery("[name='rfq_id']").val(rfq_product_id);
    });

    jQuery(".product-quantity").on('change', function(){


        jQuery( '.shop_table.cart' ).closest( 'form' ).find( 'input[name="update_cart"]' ).prop( 'disabled', false );

    });

} ); // jQuery( document ).ready



jQuery( document ).ready( function() {


    if( jQuery('#rfq_billing_country').val() !='US'){
        jQuery('#rfq_state_select').val("");
        jQuery('#rfq_state_select').hide();
        jQuery('#rfq_state_text').show();
    }else{
        jQuery('#rfq_state_text').val("");
        jQuery('#rfq_state_text').hide();
        jQuery('#rfq_state_select').show();
    }


    //  jQuery("[name='rfq_variation_id']").val(-1);
//        jQuery("[name='rfq_id']").val(rfq_product_id);
//        jQuery("[name='rfq_product_id']").val(rfq_product_id);
//        jQuery("[name='add-to-cart']").val(rfq_product_id);

  //  jQuery('.required').rules("add", {required:true});

   // jQuery("#rfqform").rules('remove');



    jQuery('form.checkout').on('click', function(){
        jQuery('form.checkout').removeAttr( 'novalidate');
    });

    /*jQuery("form.checkout").validate({
            ignore: ".cart_td .qty"
        }
        ,
        function(){

            jQuery('.cart_td table.cart_td .quantity .qty').rules('remove');
            jQuery('.qty').rules('remove');
            jQuery('.cart_td .qty').rules('remove');

            jQuery('.required').rules("add", {required:true});
        }


    );*/





});


