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
function run(){
  console.log(document.getElementById("code").value);
  var xhttp = new XMLHttpRequest();
  var old=document.getElementById("runer").className;
  xhttp.onreadystatechange = function() {
    document.getElementById("runer").innerHTML="Runng your Script...";
    document.getElementById("runer").className="btn btn-secondary";

    if (this.readyState == 4 && this.status == 200) {

      document.getElementById("runer").innerHTML = "Execute";
      document.getElementById("runer").className = old;
      console.log(this.responseText);
    }
  };
  xhttp.open("GET", "run/"+encodeURIComponent(document.getElementById("code").value), true);
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
  
  