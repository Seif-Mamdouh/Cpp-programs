-- 1.	INF-217 002
-- 2.	Mohamed
-- 3.	US_A156_SQL_S46
-- 4.	Br , Broncos



-- Damn that projects just sucked


-- 1.	List all fields in the CARDs table with descriptive headers. Sort A-Z by team code using player number as a secondary sort. 
	SELECT *
	FROM c_cards
	ORDER BY team_code ASC, player_no ASC;	

-- 2.	Write the SQL statement to list all columns in the players table for your team. 
	SELECT *
	FROM c_players 
	WHERE team_code = 'BR';

-- 3.	How many cards are for players on your team? Display the team code, count of the number of cards followed by the total cost of the cards. Add appropriate headers. Display the total cost with a “$” and 2 decimal places. 
    SELECT team_code AS "Team Code", COUNT(DISTINCT card_no) AS "Count of Cards", CONCAT('$', ROUND(SUM(PRICE), 2)) AS "Total Cost of Cards" 
    FROM c_teams NATURAL JOIN c_players NATURAL JOIN c_cards
    GROUP BY team_code;

-- 4.	List the card number, price, player name, and team code for all cards that are for quarterbacks. Order the result set by team code, then player number, then card number. Hint: Use an ANSI JOIN. 
    SELECT card_no AS "Card Number", price AS "Price", first_name AS "First Name", last_name AS "Last Name", team_code AS "Team Code"
    FROM c_cards NATURAL JOIN c_players
    WHERE position = 'QB'
    ORDER BY team_code, player_no, card_no;

-- 5.	 Display the player number, name, and position name for all players on your team. The position name is determined by converting the position codes as follows: 
-- RB = running back, QB = quarterback, TE=tight end, WR=wide receiver, LB=linebacker, CB=cornerback. Add descriptive headers. Hint: Use CASE or DECODE. 

    SELECT player_no AS "Player Number", first_name AS "First Name", last_name AS "Last Name", 
        (CASE position
        WHEN 'WR' THEN 'Wide Receiver'
        WHEN 'QB' THEN 'Quarterback'
        WHEN 'LB' THEN 'Linebacker'
        WHEN 'CB' THEN 'Cornerback'
        WHEN 'RB' THEN 'Runningback'
        ELSE 'Other position'
        END) AS "Position"
    FROM c_players
    WHERE team_code = 'BR';

-- 6.	Display the table structure for the CARDs table. 

    DESC c_cards;

-- 7.	Which cards do not have a price recorded. Display all fields in the same column order as defined in the table with descriptive labels. 

	SELECT * 
	FROM c_cards 
	WHERE price IS NULL;

-- 8.	List all players for your team. Display the Team code and player number in a single column separated by a dash (Ex: GI-10) and the player name in the next column. Add descriptive headers. 
		SELECT first_name AS "First Name", last_name AS "Last Name", CONCAT(CONCAT(team_code,'-'),player_no) AS "Team Code & Player Number" 
		FROM c_players
		WHERE team_code = 'BR';

-- 9.	Determine the average price of a card and the highest price paid for a card for your team. Round the average price to the nearest integer and display the result using a “$”. Display the highest price with a “$” and 2 positions after the decimal point. Use descriptive headings. 
		SELECT '$' || ROUND(AVG(Price)) AS "Rounded Avg",'$' || CAST(MAX(Price) AS DECIMAL(10,2)) AS "Max Price"
		FROM c_cards
		WHERE Team_Code = 'BR';	

-- 10.	Display the average price for cards by team for all teams that have an average price of at least $2.75. Include the team code and the team’s average price in the result set. 
-- Arrange the results in descending order of average price. Add descriptive headers and appropriate formatting for the average price. 	
    SELECT team_code "Team Initial", '$' || AVG(price) as "Average Price"
    FROM c_cards
    HAVING price >= 2.75
    GROUP BY team_code, price
    ORDER BY AVG(price) DESC;

-- 11.	What did each card cost? Show the card number, player last name, team name, price, price with 5% tax. If there is no price for a card, display the words No price in the price column. Order the result set by card number. Add descriptive headers and appropriate formatting to both the price and price with tax columns. Hint: Use a NULL function. 

    SELECT card_no AS "Card Number", last_name AS "Last Name", team_name AS "Team Name", team_code AS "Team Code",price ,( price*5)/ 100 + price AS "Price WITH 5 % Tax",
    CASE
        WHEN
            price IS NULL 
        THEN
            'No price in the price column' 
        ELSE
            'Price exists in the price column'
    END AS message
    FROM c_cards NATURAL JOIN c_players NATURAL JOIN c_teams
    ORDER BY card_no DESC;

-- 12.	Who is the individual on each team with the highest priced card? List the team code, player number, player last name, and card price. 
-- Sort the results by player number and a secondary sort by team code. Use descriptive headings and appropriate formatting. Hint: Use a subquery.    
    SELECT 
            team_code AS "Team Code",
            player_no AS "Player No",
            last_name as "Player Last Name",
            price AS "Highest Priced Card" 
    FROM 
            c_teams NATURAL JOIN c_players NATURAL JOIN c_cards
    WHERE
            price in (SELECT MAX(price)
            FROM c_teams
            GROUP BY team_code)

    GROUP BY
            team_code, player_no, last_name, price 

    ORDER BY 
            "Player No" ASC, "Team Code" ASC;

-- 13.	Write a statement for all cards for your team that are priced from 1.50 to 3.00 (inclusive). 
-- Order the result set by player first name. The statement must use the following format:

    My team is the < team code >. <Player first lastname> has card number < card number> which has a value of < price>.
    Ex: My team is JT. John Doe has a card number 999 which has a value of $15.27. 
    SELECT 'My team is the ' || team_code || '. ' || first_name || ' ' || last_name ||' has card number ' || card_no || ' which has a value of $' || price AS " Cards Between 1.50 - 3.00 "
    FROM c_teams NATURAL JOIN c_players NATURAL JOIN c_cards
    WHERE team_code = 'BR' AND price BETWEEN 1.50 AND 3;

-- 14.	How many months ago was your team franchised? Respond in a sentence format that includes the team name, franchise date in typical US format (Ex: February 15, 1925), and number of months. 
-- All values are to be retrieved from a table. Use appropriate formatting and a descriptive header. 

	SELECT team_name AS "Team Name", TO_CHAR(franchise_date,'Month D, YYYY') AS " Franchise Date ", EXTRACT(month FROM franchise_date) AS "DATE"
    FROM c_teams;

-- 15.	Display a list of all player positions for which you have cards for your team. 
-- Eliminate duplicates from the results list. Do not display a row If a position is not known (null). Arrange the results alphabetically. Use a descriptive heading. 

	SELECT DISTINCT(player_no) AS "Player Number", team_code AS "Team", last_name AS "Last Name", position AS "Position"
    FROM c_players
    WHERE team_code = 'BR' AND position IS NOT NULL
    ORDER BY player_no ASC, last_name ASC, position ASC;

-- 16.	Display the team name, player last name, position, and card number for all teams that were franchised on or before July 1, 1960. Your SQL command must use the date in the format shown, July 1, 1960 (not 07/01/1960 or 01-JUL-1960). Order the results in reverse order by franchise date and then by player last name. Add descriptive headers. 

		SELECT team_name, last_name, position, card_no, franchise_date
		FROM c_teams NATURAL JOIN c_players NATURAL JOIN c_cards
		WHERE TO_CHAR(franchise_date,'Month D, YYYY')  <= 'JULY 1, 1960' 
		ORDER BY franchise_date DESC, last_name DESC;








