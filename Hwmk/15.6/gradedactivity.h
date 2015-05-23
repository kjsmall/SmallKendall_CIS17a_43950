//Kendall Small
//GradedActivity Class from chapter 15

#ifndef GRADEDACTIVITY_H
#define GRADEDACTIVITY_H

class GradedActivity{
	protected:
		float score;
	public:
		GradedActivity()
			{ score = 0.0; }
		
		GradedActivity(float s)
			{ score = s; }
		
		void setScore(float s)
			{ score = s; }
			
		float getScore() const
			{ return score; }
			
		char getLetterGrade() const
			{ char letterGrade;
			  if (score > 89)
			  	letterGrade = 'A';
			  else if (score > 79)
			  	letterGrade = 'B';
			  else if (score > 69)
			    letterGrade = 'C';
			  else if (score > 59)
			    letterGrade = 'D';
			  else
			    letterGrade = 'F';
						  
			  return letterGrade; }
};

#endif
