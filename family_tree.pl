parent(raju, rajeev).
parent(reena, rajeev).
parent(ravi, raju).
parent(laxmi, raju).
child(raju, ravi).
child(rajeev, reena).

grandparent(X,Z) :- parent(X,Y), parent(Y,Z).
grandchild(X,Z) :- child(X,Y), child(Y,Z).

% grandparent(ravi, rajeev).