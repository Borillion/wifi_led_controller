const char html_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<style>
.slidecontainer {
  width: 100%;
}

.slider {
  -webkit-appearance: none;
  width: 100%;
  height: 15px;
  border-radius: 5px;
  background: #d3d3d3;
  outline: none;
  opacity: 0.7;
  -webkit-transition: .0s;
  transition: opacity .2s;
}

.slider:hover {
  opacity: 1;
}

.slider::-webkit-slider-thumb {
  -webkit-appearance: none;
  appearance: none;
  width: 25px;
  height: 25px;
  border-radius: 50%;
  background: #326C88;
  cursor: pointer;
}

.slider::-moz-range-thumb {
  width: 25px;
  height: 25px;
  border-radius: 50%;
  background: #326C88;
  cursor: pointer;
}

/* Rounded switch */

.switch {
  position: relative;
  display: inline-block;
  width: 60px;
  height: 34px;
}

.switch input { 
  opacity: 0;
  width: 0;
  height: 0;
}

.slider1 {
  position: absolute;
  cursor: pointer;
  top: 0;
  left: 0;
  right: 0;
  bottom: 0;
  background-color: #ccc;
  -webkit-transition: .4s;
  transition: .4s;
}

.slider1:before {
  position: absolute;
  content: "";
  height: 26px;
  width: 26px;
  left: 4px;
  bottom: 4px;
  background-color: white;
  -webkit-transition: .2s;
  transition: .2s;
}

input:checked + .slider1 {
  background-color: #326C88;
}

input:focus + .slider1 {
  box-shadow: 0 0 1px #326C88;
}

input:checked + .slider1:before {
  -webkit-transform: translateX(26px);
  -ms-transform: translateX(26px);
  transform: translateX(26px);
}

.slider1.round {
  border-radius: 34px;
}

.slider1.round:before {
  border-radius: 50%;
}

</style>
</head>
<body>

<h2>NodeMCU Server Control</h2>

<div class="slidecontainer">
  <p>White Channel: <span id="slider_p1"></span></p>
  <input type="range" min="0" max="1023" value="0" class="slider" id="PWM1_Slider">
</div>

<div class="slidecontainer">
  <p>Color Channel: <span id="slider_p2"></span></p>
  <input type="range" min="0" max="1023" value="0" class="slider" id="PWM2_Slider">
</div>

<div class="slidecontainer">
  <p>Blue Channel: <span id="slider_p3"></span></p>
  <input type="range" min="0" max="1023" value="0" class="slider" id="PWM3_Slider">
</div>

<div class="slidecontainer">
  <p>Fan Speed: <span id="slider_p4"></span></p>
  <input type="range" min="0" max="1023" value="0" class="slider" id="PWM4_Slider">
</div>

<script src="https://canvasjs.com/assets/script/canvasjs.min.js"></script>


<script>
var slider_1 = document.getElementById("PWM1_Slider");
var output_1 = document.getElementById("slider_p1");
var slider_2 = document.getElementById("PWM2_Slider");
var output_2 = document.getElementById("slider_p2");
var slider_3 = document.getElementById("PWM3_Slider");
var output_3 = document.getElementById("slider_p3");
var slider_4 = document.getElementById("PWM4_Slider");
var output_4 = document.getElementById("slider_p4");

output_1.innerHTML = slider_1.value;
output_2.innerHTML = slider_2.value;
output_3.innerHTML = slider_3.value;
output_4.innerHTML = slider_4.value;

slider_1.onchange = function() {
  output_1.innerHTML = this.value;
  pwm1_change(slider_1.value, slider_2.value, slider_3.value, slider_4.value);
}

function pwm1_change(val1, val2, val3, val4) {
  var xhttp = new XMLHttpRequest();
  
  const params = new URLSearchParams();
  params.set('PWM1_val',val1);
  params.set('PWM2_val',val2);
  params.set('PWM3_val',val3);
  params.set('PWM4_val',val4);

  xhttp.open("GET", "setPWM?" + params.toString(), true);
  xhttp.send();
}


slider_2.onchange = function() {
  output_2.innerHTML = this.value;
  pwm2_change(slider_1.value, slider_2.value, slider_3.value, slider_4.value);
}

function pwm2_change(val1, val2, val3, val4) {
  var xhttp = new XMLHttpRequest();
  
  const params = new URLSearchParams();
  params.set('PWM1_val',val1);
  params.set('PWM2_val',val2);
  params.set('PWM3_val',val3);
  params.set('PWM4_val',val4);

  xhttp.open("GET", "setPWM?" + params.toString(), true);
  xhttp.send();
}



slider_3.onchange = function() {
  output_3.innerHTML = this.value;
  pwm3_change(slider_1.value, slider_2.value, slider_3.value, slider_4.value);
}

function pwm3_change(val1, val2, val3, val4) {
  var xhttp = new XMLHttpRequest();
  
  const params = new URLSearchParams();
  params.set('PWM1_val',val1);
  params.set('PWM2_val',val2);
  params.set('PWM3_val',val3);
  params.set('PWM4_val',val4);

  xhttp.open("GET", "setPWM?" + params.toString(), true);
  xhttp.send();
}



slider_4.onchange = function() {
  output_4.innerHTML = this.value;
  pwm4_change(slider_1.value, slider_2.value, slider_3.value, slider_4.value);
}

function pwm4_change(val1, val2, val3, val4) {
  var xhttp = new XMLHttpRequest();
  
  const params = new URLSearchParams();
  params.set('PWM1_val',val1);
  params.set('PWM2_val',val2);
  params.set('PWM3_val',val3);
  params.set('PWM4_val',val4);

  xhttp.open("GET", "setPWM?" + params.toString(), true);
  xhttp.send();
}

</script>

</body>
</html>
)=====";
