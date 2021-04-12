function Build() {
  var xhttp = new XMLHttpRequest();
  var old=document.getElementById("Build").className;
  xhttp.onreadystatechange = function() {
    document.getElementById("Build").innerHTML="compiling your Reltt...";
    document.getElementById("Build").className="btn btn-secondary";

    if (this.readyState == 4 && this.status == 200) {

      document.getElementById("Build").innerHTML = "Build!";
      document.getElementById("Build").className = old;
      console.log("State");
    }
  };
  xhttp.open("GET", "mod/compile", true);
  xhttp.send();


}
var filex;
function read(file){
  filex=file;
  var xhttp = new XMLHttpRequest();
  var old=document.getElementById(file+"Ex").className;
  console.log("Save.onclick="+"save('"+file+"')");
  xhttp.onreadystatechange = function() {
    document.getElementById(file+"Ex").innerHTML="Running Script "+file;
    document.getElementById(file+"Ex").className="btn btn-secondary";
    
    if (this.readyState == 4 && this.status == 200) {

      document.getElementById(file+"Ex").innerHTML = "Execute";
      document.getElementById(file+"Ex").className = old;
      document.getElementById("console").innerHTML=this.responseText;
    }
  };
  xhttp.open("GET", "/read/"+file);
  xhttp.send();
}
function save(){
  file=filex
  console.log("save");
  var xhttp = new XMLHttpRequest();
  var old=document.getElementById("Save").className;
  content=document.getElementById("console").innerHTML;
  xhttp.onreadystatechange = function() {
    document.getElementById("Save").innerHTML="Saving Script "+file;
    document.getElementById("Save").className="btn btn-secondary";
    
    if (this.readyState == 4 && this.status == 200) {

      document.getElementById("Save").innerHTML = "Save";
      document.getElementById("Save").className = old;
      //document.getElementById("console").innerHTML=this.responseText;
    }
  };
  xhttp.open("GET", "/save/"+file+"/"+content);
  xhttp.send();
}
function run(file){
  var xhttp = new XMLHttpRequest();
  var old=document.getElementById(file+"Ex").className;
  xhttp.onreadystatechange = function() {
    document.getElementById(file+"Ex").innerHTML="Running Script "+file;
    document.getElementById(file+"Ex").className="btn btn-secondary";
    if (this.readyState == 4 && this.status == 200) {

      document.getElementById(file+"Ex").innerHTML = "Execute";
      document.getElementById(file+"Ex").className = old;
      document.getElementById("console").innerHTML=this.responseText;
    }
  };
  xhttp.open("GET", "/run/"+file);
  xhttp.send();
}

function switchs(name=String) {
    
    var lxhttp=new XMLHttpRequest();
    lxhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {

        var xhttp = new XMLHttpRequest();
        
        if (this.responseText=="1"){
          xhttp.onreadystatechange = function() {
            if (this.readyState == 4 && this.status == 200) {

              
            }

          }
          document.getElementById(name).className = "btn btn-outline-success";
          document.getElementById(name).innerHTML="Add"
          xhttp.open("GET", "mod/D/"+name, true);
          xhttp.send();
        }
        else if (this.responseText=="0"){
          xhttp.onreadystatechange = function() {
            if (this.readyState == 4 && this.status == 200) {

              
            }
          }
          xhttp.open("GET", "mod/A/"+name, true);
          xhttp.send();
          document.getElementById(name).className ="btn btn-outline-danger";
          document.getElementById(name).innerHTML="Delete"
        }
        
          console.log(name+"  "+lxhttp.responseText)
        
        

      };
    }
      lxhttp.open("GET", "mod/exist/"+name, true);
      lxhttp.send();
    };
  
  