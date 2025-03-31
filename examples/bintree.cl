class Node {
    value: String;
    left: Node;
    right: Node;

    -- Inicijalizacija čvora sa string vrijednošću
    init(v: String): Node {
        {
            value <- v;
            left <- void;
            right <- void;
            self;
        }
    };

    -- Funkcija za umetanje novog stringa u binarno stablo
    insert(new_value: String): Node {
        if isvoid value then {
            value <- new_value;
        } else if new_value < value then {
            if isvoid left then {
                left <- (new Node).init(new_value);
            } else {
                left <- left.insert(new_value);
            }
        } 
        else {
            if isvoid right then {
                right <- (new Node).init(new_value);
            } else {
                right <- right.insert(new_value);
            }}
        self;
    }


    print_infix(): Object {
        if not isvoid left then {
            left.print_infix();
        }
        out_string(value);
            --out_string("\n");
        if not isvoid right then {
            right.print_infix();
        }
    };
};

class Main inherits IO {
    main(): Object {
        let tree: Node <- (new Node).init("m") in {
            -- Dodavanje elemenata u stablo
            tree <- tree.insert("a");
            tree <- tree.insert("z");
            tree <- tree.insert("c");
            tree <- tree.insert("x");

            -- Ispis stabla u infix redoslijedu
            out_string("Infix ispis stabla:\n");
            tree.print_infix();
        }
    };
};


