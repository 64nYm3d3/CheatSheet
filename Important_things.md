# My Toppers Order, **VERY IMPORTANT**

When alone I get a buffalo chicken pizza with sundried tomatoes on it,3 cheese styx, and a side of garlic as well as bleu cheese. Will modify. Please order as follows:

~~~
URL="https://toppers.com/myorder/cgi-bin/order.cgi"

O="order=Order"
A="amount_%d=%%d&amount_foil_container_%d=%%d"

function order_lunch() {
  if [[ -n "$@" ]]; then
    curl -u "$USER":"$PASSWORD" \
         -d $(printf $(printf "$O&$A&$A&$A&$A" 0 0 1 1 2 2 3 3) \
                     "${@:2:8}") \
         "$URL";
  else
    echo "Nothing to order.";
  fi;
}
