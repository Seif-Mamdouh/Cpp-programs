Class Project
Code to create cookie tables


CREATE TABLE a_ingredients
(id NUMBER(4,0) PRIMARY KEY,
 description VARCHAR2(50) NOT NULL
);

CREATE TABLE a_cookies
(code VARCHAR2(4) PRIMARY KEY,
 name VARCHAR2(20) NOT NULL,
 shape VARCHAR2(12),
 time_of_year VARCHAR2(9)
);

CREATE TABLE a_ingredient_lists
(igt_id NUMBER(4,0),
 cke_code VARCHAR2(4),
 quantity VARCHAR2(15),
 CONSTRAINT ilt_id_code_PK PRIMARY KEY (igt_id, cke_code),
 CONSTRAINT ilt_id_FK FOREIGN KEY (igt_id) REFERENCES a_ingredients(id),
 CONSTRAINT ilt_code_FK FOREIGN KEY (cke_code) REFERENCES a_cookies(code)
);

-----------------------------------

Commands to drop the tables if you wish to start again. You must drop 
a_ingredient_lists BEFORE the others since it has the FK

DROP TABLE a_ingredients;
DROP TABLE a_cookies;
DROP TABLE a_ingredient_lists;

