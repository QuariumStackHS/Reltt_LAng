
function add_module() {

        var Desc=document.getElementById("Desc").value;
        var cppcons=document.getElementById("Constructor").value;
        var Developer=document.getElementById("Dev").value;
        var osq=document.getElementById("OSdrop").value;
        var versionq=document.getElementById("Version").value;

        
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          //document.getElementById("Build").innerHTML="compiling your Reltt...";
          //document.getElementById("Build").className="btn btn-secondary";
      
          if (this.readyState == 4 && this.status == 200) {
            
          }
        };
        location.href = "/Up/"+cppcons+"/"+Developer+"/"+Desc+"/"+versionq+"/"+osq;

  }