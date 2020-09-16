function sameSubnet(ipStringNameA, ipStringNameB, maskStringName)
{
  var ipNameA = ipStringNameA.split(".");
  var ipNameB = ipStringNameB.split(".");
  var maskName = maskStringName.split(".");
  var tmpA, tmpB, tmpM;
  for (var i=0; i<4; i++)
  {
    tmpA = eval(ipNameA[i]);
    tmpB = eval(ipNameB[i]);
    tmpM = eval(maskName[i]);
    if (eval(tmpA&tmpM)!=eval(tmpB&tmpM))
      return false;
  }
  return true;
}

function blockui()
{
     $.blockUI
     ({
       //message: '<h1><img src="/graphics/busy.gif" />  Processing...</h1>',
       message: '<h1>Processing...</h1>',
       timeout: 50000,
       css: {
            border: 'none',
            padding: '15px',
            backgroundColor: '#000',
            '-webkit-border-radius': '10px',
            '-moz-border-radius': '10px',
            opacity: .5,
            color: '#fff'
           }
   });
   // Another method to set the timeout to unlock UI blocking
   //setTimeout($.unblockUI, 90000);
}
