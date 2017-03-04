var p=0,q=-12;
 function a(){
   if(window.setTimeout&&document.getElementsByTagName)
     
  {
    
    var o=12*(2<<6);
    var b=document.getElementsByTagName("pre")[0];
    b.style.top=(p-o)+"pt";
    var l=document.getElementsByTagName("b");
    var o=-(p-o)+"pt";
    for(var a in l)
    {
      if(l[a].style)l[a].style.top=o;
    }
    p+=q;
    if(p<-2<<9||p>=0)
      q=-q;
      window.setTimeout(this.a,2<<6);
    
    }
  
 }

a();
