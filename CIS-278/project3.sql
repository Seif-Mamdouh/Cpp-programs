-- //1.Create A_QUESTION_BANKS, A_STUDENTS, A_INSTRUCTORS, and A_COURSE_CODES tables with appropriate constraints.
-- // Provide text and full window screenshots of each create statement. (4 screenshots)

-- Answer: 

A_QUESTION_BANKS Table:
CREATE TABLE a_question_banks
(
question_no              VARCHAR2(5), 
question_text            VARCHAR2(50)
     
);

A_STUDENTS Table:

CREATE TABLE a_students
(
student_id             VARCHAR2(5), 
first                  VARCHAR2(10),
last                   VARCHAR2(20),
email                  VARCHAR2(80) 
     
);

 A_INSTRUCTORS Table:

CREATE TABLE a_instructors
(
instructor_id             VARCHAR2(5), 
first                  VARCHAR2(10),
last                   VARCHAR2(20),
email                  VARCHAR2(80),
department             VARCHAR2(5), 
rank                   VARCHAR2(20)
     
);

A_COURSE_CODES Table:

CREATE TABLE A_COURSE_CODES 
(
instructor_id             VARCHAR2(5), 
course_no                 VARCHAR2(15)
     
);


-- -- 2.	Create A_SURVEY_ENTRIES table without any constraints and then alter the table to add all required constraints. 
-- Provide text and full window screenshots of each statement. 
-- (There will be one screenshot of the create and multiple screenshots as the constraints are added to the table.)

CREATE TABLE A_SURVEY_ENTRIES(
		student_id                VARCHAR2(5), 
		course_no                 VARCHAR2(20), 
		question_no               VARCHAR2(5), 
		reponse                   VARCHAR2(5), 
		response_date             DATE
	);

-- Survey_Entries inheirts from Students table (student_id) 
-- Survey_Entries inheirts from Course_Codes table (course_no) 
-- Survey_Entries inheirts from Questions_Banks table (question_no)

ALTER TABLE Survey_Entries
ADD CONSTRAINT survey_entries_ibfk_1 FOREIGN KEY (student)
REFERENCES Student (student) ON DELETE CASCADE ON UPDATE NO ACTION


ALTER TABLE A_SURVEY_ENTRIES
ADD CONSTRAINT surve_entr_fk FOREIGN KEY (course_no)
REFERENCES Course_Codes (course_no) ON DELETE CASCADE ON


ALTER TABLE a_survey_entries 
ADD CONSTRAINT surv_enter_fk FOREIGN KEY (question_no)
   REFERENCES a_question_banks (question_no) ON DELETE CASCADE;



-- Adding an Alter table to uodate some Primary keys inside the tables
ALTER TABLE a_students
ADD CONSTRAINT stdnt_id_pk PRIMARY KEY (student_id);


ALTER TABLE a_course_codes
ADD CONSTRAINT crse_cde_pk PRIMARY KEY (course_no);


ALTER TABLE a_question_banks
ADD CONSTRAINT qstns_bnk_pk PRIMARY KEY (question_no);



-- 3.	Insert data. Create one block of insert statements for each table that uses the data that is provided expanded by
--  the rows described below. Provide text and full window screenshots for each insert block (5 screenshots)

-- This is used to insert data into the tables 

-- a.	QUESTION_BANKS – add 6 survey questions for a total of 10 questions


INSERT ALL 
INTO a_question_banks(question_no, question_text)
VALUES ('00001', 'How did you like the course?')

INTO a_question_banks(question_no, question_text)
VALUES ('00002', 'How did you like the instructor?')

INTO a_question_banks(question_no, question_text)
VALUES ('00003', 'How did you like the classmates?')

INTO a_question_banks(question_no, question_text)
VALUES ('00004', 'How did you like the classroom?')

INTO a_question_banks(question_no, question_text)
VALUES ('00005', 'How did you like the projects?')

INTO a_question_banks(question_no, question_text)
VALUES ('00006', 'Rate the instructor from 1 - 10')

INTO a_question_banks(question_no, question_text)
VALUES ('00007', 'Rate the course from 1 - 10')

INTO a_question_banks(question_no, question_text)
VALUES ('00008', 'Rate the classroom from 1 - 10')

INTO a_question_banks(question_no, question_text)
VALUES ('00009', 'Rate the projects from 1 - 10')

INTO a_question_banks(question_no, question_text)
VALUES ('00010', 'Rate your classmates from 1 - 10')

SELECT *
FROM DUAL;


-- b.	STUDENTS – add your own data and 4 family members for a total of 8 students. 
-- Be to enter your Bergen email address and Bergen student ID in your row.

INSERT ALL 
INTO a_students (student_id, first, last, email) 
VALUES ('08477', 'Seifeldeen', 'Mohamed', 'smohamed134599@me.bergen.edu')

INTO a_students (student_id, first, last, email) 
VALUES ('00001', 'Hoor', 'Khaled', 'hoorkhaled12@gmail.com')

INTO a_students (student_id, first, last, email) 
VALUES ('02002', 'Judy', 'Al-Midani', 'Judy@gmail.com')

INTO a_students (student_id, first, last, email) 
VALUES ('32011', 'Ariana', 'Perez', 'arian123@gmail.com')

INTO a_students (student_id, first, last, email) 
VALUES ('13200', 'Jackie', 'Peterson', 'jackiepete@gmail.com')

INTO a_students (student_id, first, last, email) 
VALUES ('12402', 'Jose', 'Zuniga', 'josezuniga@estuniga.com')

INTO a_students (student_id, first, last, email) 
VALUES ('15402', 'Renelle', 'Ramriez', 'renelle@hotmail.com')

INTO a_students (student_id, first, last, email) 
VALUES ('10102', 'Esra', 'Ydiz', 'esra@montclair.edu')

SELECT *
FROM DUAL;


-- c.	COURSE_CODES – Add a mix of INF, CIS, and MAT courses in your degree program so you have a total of 10 courses listed.
       ALTER TABLE a_instructors
ADD CONSTRAINT intctr_id_pk PRIMARY KEY (instructor_id);

ALTER TABLE a_course_codes
ADD CONSTRAINT crse_cd_fk FOREIGN KEY (instructor_id)
   REFERENCES a_instructors (instructor_id) ON DELETE CASCADE;
	        
INSERT ALL
INTO a_course_codes (course_no, instructor_id)
VALUES('INF-277','34511')

INTO a_course_codes (course_no, instructor_id)
VALUES('INF-222','23445')

INTO a_course_codes (course_no, instructor_id)
VALUES('CIS-188','26264')

INTO a_course_codes (course_no, instructor_id)
VALUES('MAT-112','62671')

INTO a_course_codes (course_no, instructor_id)
VALUES('CIS-327','73472')

INTO a_course_codes (course_no, instructor_id)
VALUES('MAT-100','46323')

INTO a_course_codes (course_no, instructor_id)
VALUES('CIS-271','74123')

INTO a_course_codes (course_no, instructor_id)
VALUES('INF-721','92367')

INTO a_course_codes (course_no, instructor_id)
VALUES('INF-233','32156')

INTO a_course_codes (course_no, instructor_id)
VALUES('CIS-862','87121')
SELECT *
FROM DUAL;


-- d.	INSTRUCTORS – Add instructors to match the courses in the COURSE_CODES table

		INSERT ALL 
INTO a_instructors (instructor_id, first, last, email, department, rank)
VALUES('34511', 'Sharon', 'Kim', 'sharonkim@gail', 'INF', 'Professor')

INTO a_instructors (instructor_id, first, last, email, department, rank)
VALUES('23445', 'Anita', 'Verno', 'anita@begren.edu', 'INF', 'Professor')

INTO a_instructors (instructor_id, first, last, email, department, rank)
VALUES('26264', 'Fasial', 'Aljmal', 'af@bergen.edu', 'CIS', 'Professor')

INTO a_instructors (instructor_id, first, last, email, department, rank)
VALUES('62671', 'Sofia', 'Wang', 'sof@cornell.edu', 'MAT', 'Professor')

INTO a_instructors (instructor_id, first, last, email, department, rank)
VALUES('73472', 'Oscar', 'Martinez', 'oscar@cornell.edu', 'CIS', 'Professor')

INTO a_instructors (instructor_id, first, last, email, department, rank)
VALUES('46323', 'Marwan', 'Gabreil;', 'falco@middleessex@gmail.com', 'MAT', 'Professor')

INTO a_instructors (instructor_id, first, last, email, department, rank)
VALUES('74123','George', 'Chudyk', 'gerorge@bergen.edu', 'CIS', 'Professor')

INTO a_instructors (instructor_id, first, last, email, department, rank)
VALUES('92367', 'Mamdouh', 'ElSayed', 'mamdouh78@cairo.com', 'INF', 'Professor')

INTO a_instructors (instructor_id, first, last, email, department, rank)
VALUES('32156', 'Ghada', 'Khattab', 'ghada@cairo.com', 'INF', 'Professor')

INTO a_instructors (instructor_id, first, last, email, department, rank)
VALUES('87121', 'Han', 'Ye', 'han@wellsheet.com', 'CIS', 'Professor/Engineer')

SELECT *
FROM DUAL;

-- e.	SURVEY_ENTRIES – Choose 2 of your courses and provide answers to every survey question. 

BEGIN

INSERT INTO a_survey_entries(student_id, course_no, question_no, response, response_date)
VALUES('08477','INF-721','00003','I give it a 3', TO_DATE('11/12/2019', 'fxMM/DD/YYYY'));

INSERT INTO a_survey_entries(student_id, course_no, question_no, response, response_date)
VALUES('02002','CIS-862','00004','Maybe a 8/10', TO_DATE('12/11/2019', 'fxMM/DD/YYYY'));

INSERT INTO a_survey_entries(student_id, course_no, question_no, response, response_date)
VALUES('32011','CIS-862' ,'00002','Def a 9', TO_DATE('11/10/2019', 'MM/DD/YYYY'));

INSERT INTO a_survey_entries(student_id, course_no, question_no, response, response_date)
VALUES('13200','CIS-862','00001','Had the worst time 2', TO_DATE('10/10/2019', 'fxMM/DD/YYYY'));

INSERT INTO a_survey_entries(student_id, course_no, question_no, response, response_date)
VALUES('12402', 'CIS-862' ,'00005','Not the greatest time 3', TO_DATE('11/30/2019', 'fxMM/DD/YYYY'));

INSERT INTO a_survey_entries(student_id, course_no, question_no, response, response_date)
VALUES('15402','INF-721','00006','I has the a bad time 4', TO_DATE('12/13/2019', 'fxMM/DD/YYYY'));

INSERT INTO a_survey_entries(student_id, course_no, question_no, response, response_date)
VALUES('10102','INF-721','00007','It was ok, 7', TO_DATE('12/10/2019', 'fxMM/DD/YYYY'));

INSERT INTO a_survey_entries(student_id, course_no, question_no, response, response_date)
VALUES('08477','INF-721','00008','I would say a 7', TO_DATE('10/20/2019', 'fxMM/DD/YYYY'));

INSERT INTO a_survey_entries(student_id, course_no, question_no, response, response_date)
VALUES('10102', 'CIS-862' ,'00009','Great time! I give it a 10 ', TO_DATE('11/15/2019', 'fxMM/DD/YYYY'));

INSERT INTO a_survey_entries(student_id, course_no, question_no, response, response_date)
VALUES('15402','INF-721','00010','Amazing time! I say a 10', TO_DATE('10/03/2019', 'fxMM/DD/YYYY'));

COMMIT;
END;

-- 4.	Describe each table and provide a screenshot of each (5 screenshots)

A_QUESTION_BANKS, A_STUDENTS, A_INSTRUCTORS, and A_COURSE_CODES a_survey_entries

-- and Just di the command DESC table_name, i aint gonna do it lmfaoooo


-- 5.	For each table, run a command that provides the constraint_name, index_name and constraint_type 
-- and provide the text and screenshot or each. Hint: user_constraints.  (5 screenshots)

-- For this question we it's gonna be reppetitve

SELECT tavle comulmn 
FROM user_constraints
WHERE table_name = 'table_name';

-- Simple

-- 6.	Display all data in each table, in default order, with the col names as headers, sorted by the primary key in the table. (5 screenshots)

-- for 6 just put the column names and table name exactly as she states them in the question into a SELECT statement, w the specific table name in the WHERE part being the table you need in uppercase. 

-- A_QUESTION_BANKS, A_STUDENTS, A_INSTRUCTORS, and A_COURSE_CODES a_survey_entries
	

SELECT * 
FROM user_tab_columns
WHERE table_name = 'A_STUDENTS';


SELECT * 
FROM user_tab_columns
WHERE table_name = 'A_INSTRUCTORS';


