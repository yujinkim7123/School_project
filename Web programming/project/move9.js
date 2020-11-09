var x =0;
          
function show() {
	if(x == 0){
	document.getElementById("back2").src = "star1.png";
	x++;
	}
	else if(x == 1){
		document.getElementById("back2").src = "star.png";
		x = 0;
	}
	setTimeout(show, 2000);	
}

window.onload = function() {
	show();
}

var context = document.getElementById("canvas").getContext("2d");
var radius  = document.getElementById("canvas").width/2;

setInterval(function(context, radius) {
    makeClockTool(this.context, this.radius);
    makeNumberTool(this.context, this.radius);
    makeArrowTool(this.context, this.radius);
}, 1000);


function makeClockTool(context, radius) {
    context.beginPath();
    context.arc(radius, radius, radius, 0, Math.PI * 2);
    context.fillStyle = "black";
    context.fill();
    context.stroke();
    
    context.beginPath();
    context.arc(radius, radius, 10, 0, Math.PI * 2);
    context.fillStyle = "white";
    context.fill();
    context.stroke();
} 

function makeNumberTool(context, radius) {
    context.font = 30 + "px Arial";
    for (var i = 0; i < 12; i++) {
        var x = 120* Math.cos(Math.PI* (30 * i)/ 180)+ radius- 20;
        var y = 120* Math.sin(Math.PI* (30 * i)/ 180)+ radius+ 20;
        var number = 0;
        if(i <= 9) {
            number = i+ 3;
        } else {
            number = i- 9;
        }
        context.fillText(number.toString(), x, y);
    }
}
    
function makeArrowTool(context, radius) {
    var now = new Date();
    var hour = now.getHours();
    var minute = now.getMinutes();
    var second = now.getSeconds();
    
    
    context.beginPath();
    context.moveTo(radius, radius);
    context.lineTo(100* Math.cos(Math.PI* ((second* 6)- 90)/ 180)+ radius, 
                   100* Math.sin(Math.PI* ((second* 6)- 90)/ 180)+ radius);
    context.lineWidth= 1;
    context.strokeStyle= "white";
    context.stroke();
    
    
    context.beginPath();
    context.moveTo(radius, radius);
    context.lineTo(100* Math.cos(Math.PI* (((minute* 6)- 90)+ (second* (6/ 60)))/ 180)+ radius, 
                   100* Math.sin(Math.PI* (((minute* 6)- 90)+ (second* (6/ 60)))/ 180)+ radius);
    context.lineWidth= 3;
    context.strokeStyle= "white";
    context.stroke();
    
    
    context.beginPath();
    context.moveTo(radius, radius);
    context.lineTo(50* Math.cos(Math.PI* (((hour* 30)- 90)+ (second* (6/ 60/ 60)))/ 180)+ radius, 
                   50* Math.sin(Math.PI* (((hour* 30)- 90)+ (second* (6/ 60/ 60)))/ 180)+ radius);
    context.lineWidth= 6;
    context.strokeStyle= "white";
    context.stroke();
    
}
          
function check(){
	var email = document.getElementById("eml");
    var num1 = document.getElementById("phone");
    var num2 = document.getElementById("card1");
    var num3 = document.getElementById("card2");
	var exp = /^[0-9]+$/;
	var exp1 = /^[a-zA-Z0-9_\.\-]+\@(([a-zA-Z0-9\-])+\.)+([a-zA-Z0-9]{2,})+$/;
	var exp2 = /[0-9]{3}[0-9]{4}[0-9]{4}/;
	 if (email.value.match(exp1)) {
     } else {
         alert('이메일 형식이 틀립니다!');
         email.focus();
         return false;
     }
	 if (num1.value.match(exp2)) {
     } else {
         alert('숫자만 입력하세요!');
         num1.focus();
         return false;
     }
	 if (num2.value.match(exp)) {
     } else {
         alert('카드의 숫자만 입력하세요!');
         num2.focus();
         return false;
     } 	
	 if (num3.value.match(exp)) {
     } else {
         alert('CRC 숫자만 입력하세요!');
         num3.focus();
         return false;
     } 	
	
}
