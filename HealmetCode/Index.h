const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
<title>Sensores Casco</title>
<style>
hr.blue1{
  border: 1px solid blue;  
}
h1.a1{
  font-family: Arial;
  }

h2.a2{
  font-family: Arial;
  }
</style>
<head>
<body style="background-color: rgb(18,18,18,255) ; color: #121212 ; ">
<div class="card">
  <h2 class="a2" style ="color:#868686;">Sensores stormtrooper</h2><br>
  <h1 class="a1" style ="color:#868686;">
  Alcohol Value: <span id="MQ3Value">0</span><br>
  <hr class = "blue1">
  <br>
  Temperature Value: <span id="temp">0</span><br>
  <hr class = "blue1">
  <br>
  Humidity Value: <span id="humi">0</span> %<br>
  <hr class = "blue1">
  </h1>
  <h1>""</h1>
  <h1>""</h1>
 
</div>   
<script>

setInterval(function() {
  // Call a function repetatively with 2 Second interval
  getData();
  getDataTemp();
  getDataHumi()
}, 2000); //2000mSeconds update rate

function getData() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("MQ3Value").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "readADC", true);
  xhttp.send();
}

function getDataTemp() {
  
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("temp").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "temp", true);
  xhttp.send();
}

function getDataHumi() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("humi").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "humi", true);
  xhttp.send();
}
</script>
</body>
</html>
)=====";
