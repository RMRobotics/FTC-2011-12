///////////////////////////////////////////////////////
//RM ROBOTICS TELEOP TEMPLATE
//Good Stuff! This template contains all
//the necessary functions and comments to
//make a good Teleop Program!
///////////////////////////////////////////////////////
#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.


void initializeRobot()
{
  //This function is used to set up variables, sensors, and servo positions.
  //For the most part, this function won't have much in it.
  return;
}


//SKIP THIS FOR NOW, START READING AFTER THE BIG "START CODE"
//START READING HERE ONLY AFTER YOU REACH THE BOTTOM
////////////////////////////////////////////////////////////////////
void otherFunction(int parameter){
  //This is a function. Functions are blocks of code that can
  //be called separately. They do not have access to all of the variables
  //defined in the main program, so you must define new variables here
  //and pass the function any numbers you want it to have through parameters.
  //In the function, you must also specifiy the type of each parameter, which
  //is in this case an integer. The function's "call" at the end of the
  //program (otherFunction(x);) passed the value of x, which this function
  //assigned to its own variable named "parameter"

  //This return line will basically put out an answer for the function.
  //The "answer" is useful if the function computes a mathematical equation.
  //The answer must be in the type specified before the function, which is
  //for this function a void, which is an empty variable. Void functions are
  //used for functions that control motors, etc., without passing back any
  //sort of answer.
return;
}

//Oh, and this // means a comment. Comments are for humans and are ignored
//by the machine. Before code included comments, programmers had to invent
//really crafty ways of explaining what their code did, using only other statements
//in the code. This got really annoying, so all major coding languages added comments.

/* You can also use this slash and asterisk combination
    to
    make long
    multiple-line-long
    comments! Or to comment out a block of code you want to save but not to run.*/

//And so, I now present my rules of code. Read them, follow them, and then you're done!

//#1. Comment and space out your code. This improves readability and ease of understanding.
//#2. Use logical variable names. This improves readability and ease of understanding.
//#3. Don't use spaghetti code. If you don't know what that is, don't bother finding out. IT'S BAD.
//#4. When possible, don't just write over others' code. Comment it out.
//#5. Save often.


    // So yeah, that's pretty much it. Best of luck!

////////////////////////////////////////////////////////////////////

task main()
{
  //This is the real code for the robot. All actions need to be in here.
  initializeRobot();

  //waitForStart();   // wait for start of tele-op phase; Needed for the Samantha WiFi module;UNCOMMENT IN FINAL VERSION

  while (true)
  {
	  //This code will run until stopped by the computer
    //Joystick controls and motor actions will go in here
    //This is where the bulk of the code will go

    //SSSSS TTTTT   A   RRRR  TTTTT      CCCC  OOO  DDDD  EEEEE !!!
    //SS      T    A A  R   R   T       C     O   O D   D E     !!!
    //SSSSS   T   A   A RRRR    T       C     O   O D   D EEEE  !!!
    //   SS   T   AAAAA R  R    T       C     O   O D   D E
    //SSSSS   T   A   A R   R   T        CCCC  OOO  DDDD  EEEEE !!!


    //And now, to teach you all some basic programming

    int x=1;
    //This is a variable declaration.
    //Variables must be defined and given a type
    //before they can be used. Our variable is x,
    //an integer with the value of 1.

    if(x==1){
      //This is an if statement.
      //If the condition in the parentheses is true,
      //this block of code in the curly brackets is
      //executed.

    }else if(x==2){
      //This is an else-if
      //Else-ifs are blocks that come after an if
      //statement. They are alternate conditions
      //with extra blocks of code. If an if and an else if
      //are both true, or if two else-ifs are true, only the
      //first one will be executed
    }else{
      //This is an else block.
      //Else statements are executed if all other
      //if conditions are false. They can be placed
      //at the end of an if-elseif block
    }

    if(x<10 && x>0){
      //If statements can have multiple conditions,
      //connected by logic operators. For example,
      //&& is the AND symbol, meaning both conditions
      //need to be true.
    }

    if(x<10 || x>0){
      //Here, the two conditions are connected by ||
      //the OR symbol. OR means only one of the conditions
      //needs to be true
    }

    if( (x<0 || x==1) && x!=42){
      //Logic and conditions can be grouped to form
      //compound conditions. Now is also a good time
      //to explain what all the symbols mean.

      //  == means equals
      //  > means greater than
      //  < means lesser than
      //  >= means greater than or equal to
      //  <= means lesser than or equal to
      //  ! means NOT, that is, the opposite
      //          of the specified condition
      //  != means not equal to
      //  && means AND
      //  || means OR

      // While I'm at it, let's also explain the math

      // + means add. No surprise there.
      // - means subtract. Still pretty kindergarten.
      // * means multiply.
      // / means divide.

      // ^ means to the power of.
      // sqrt() means square root of.
      // You can use ^ and fractions to get cube roots, etc.
      // ie. 8 ^ 1/3 = 2;

      // ++ means add 1 to the value of (also known as increment)
      // -- means subtract 1 (AKA decrement)

      // += means set the variable equal to itself plus the other number.
      //          For example, if x=1,
      //                  x+=2;
      //          would set x to 3.
      // -= means set the variable equal to itself minus the other number.




      // And there are all sorts of other fun functions,
      // like sin(), cos(), random[], etc. We probably won't need those.
  }

    while(x<10){
      //This is a while loop.
      //While loops execute all code inside of them
      //as long as the condition in parentheses is true.
      //This can be dangerous! For example, if this program
      //was run, this loop would run endlessly, because x will
      //stay equal to 1, which is less than 10
    }

    for(x=1;x<10;x++){
      //This is a for loop.
      //For loops are very useful, and will run for a specified
      //number of times. The first parameter is the start condition.
      //This becomes true when the loop first runs. The second is the
      //end condition. The loop will run as long as this is true. The last
      //is the increment. This will be executed at the end of each loop,
      //so each time this loop runs, x will increase by 1, until x is no
      //longer less than 10. Most often, the increment is 1, written as ++.
    }

    otherFunction(x); //go on back to the top now, where you should see otherFunction()
  }
}
