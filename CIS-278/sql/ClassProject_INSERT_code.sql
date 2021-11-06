Sample data for Cookie Class Project
3 blocks of data

BEGIN
  INSERT INTO a_ingredients
  VALUES (101, 'Triple chocolate cookie dough');
  INSERT INTO a_ingredients
  VALUES (102, 'Candy sprinkles');
  INSERT INTO a_ingredients
  VALUES (103, 'Chocolate candies');
  INSERT INTO a_ingredients
  VALUES (104, 'Candy corn');
  INSERT INTO a_ingredients
  VALUES (105, 'String licorice');
  INSERT INTO a_ingredients
  VALUES (106, 'Chocolate chip cookie dough');
  INSERT INTO a_ingredients
  VALUES (107, 'Chocolate frosting');
  INSERT INTO a_ingredients
  VALUES (108, 'Vanilla candy coating');
  INSERT INTO a_ingredients
  VALUES (109, 'Peanut butter filled sandwich cookies');
  INSERT INTO a_ingredients
  VALUES (110, 'Chocolate chips');
  INSERT INTO a_ingredients
  VALUES (111, 'Sugar cookie dough');
  INSERT INTO a_ingredients
  VALUES (112, 'Flour');
  INSERT INTO a_ingredients
  VALUES (113, 'Decorating gel');
  INSERT INTO a_ingredients
  VALUES (114, 'Colored sugar');
  COMMIT;
END;


BEGIN
   INSERT INTO a_cookies
   VALUES ('CAT', 'Chocolate Cat', 'Animal', NULL);
   INSERT INTO a_cookies
   VALUES ('WOLF', 'Werewolf', 'Supernatural', 'Halloween');
   INSERT INTO a_cookies
   VALUES ('GHST', 'Ghost', 'Supernatural', 'Halloween');
   INSERT INTO a_cookies
   VALUES ('FOOT', 'Football', 'Object', 'Football');
   INSERT INTO a_cookies
   VALUES ('HAND', 'Handprint', 'Human', NULL);
   COMMIT;
END;


BEGIN
   INSERT INTO a_ingredient_lists
   VALUES(101, 'CAT', '1 package');
   INSERT INTO a_ingredient_lists
   VALUES(102, 'CAT', 'as desired');
   INSERT INTO a_ingredient_lists
   VALUES(103, 'CAT', 'as desired');
   INSERT INTO a_ingredient_lists
   VALUES(104, 'CAT', 'as desired');
   INSERT INTO a_ingredient_lists
   VALUES(105, 'CAT', 'as desired');

   INSERT INTO a_ingredient_lists
   VALUES(106, 'WOLF', '1 package');
   INSERT INTO a_ingredient_lists
   VALUES(107, 'WOLF', '1-1/2 cups');
   INSERT INTO a_ingredient_lists
   VALUES(103, 'WOLF', '1as desired');

   INSERT INTO a_ingredient_lists
   VALUES(108, 'GHST', '12 oz');
   INSERT INTO a_ingredient_lists
   VALUES(109, 'GHST', '1 package');
   INSERT INTO a_ingredient_lists
   VALUES(110, 'GHST', '64');

   INSERT INTO a_ingredient_lists
   VALUES(111, 'FOOT', '1 package');
   INSERT INTO a_ingredient_lists
   VALUES(112, 'FOOT', '1/4 cup');
   INSERT INTO a_ingredient_lists
   VALUES(107, 'FOOT', '1 lb');
   INSERT INTO a_ingredient_lists
   VALUES(113, 'FOOT', 'as desired');

   INSERT INTO a_ingredient_lists
   VALUES(111, 'HAND', '1 package');
   INSERT INTO a_ingredient_lists
   VALUES(112, 'HAND', '1/4 cup');
   INSERT INTO a_ingredient_lists
   VALUES(113, 'HAND', 'as desired');
   INSERT INTO a_ingredient_lists
   VALUES(114, 'HAND', 'as desired');

   COMMIT;
END;


