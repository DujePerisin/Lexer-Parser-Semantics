class Main inherits IO {
    b1 : Int <- new Int;
    b2 : Int <- new Int;
    p1 : Int <- new Int;
    p2 : Int <- new Int;

    main():Object {{
    out_string("Unesi bazu: ");
    b1 <- in_int();

    out_string("Unesi eksponent: ");
    p1 <- in_int();
    out_string("\n");

    b2 <- b1;
    p2 <- p1;

    b1 <- powR(b1,p1);
    b2 <- powI(b2,p2);

    out_string("Rekurzivno: ");
    out_int(b1);
    out_string("\n");

    out_string("Iterativno: ");
    out_int(b2);
    out_string("\n");
    }};


    powR(i: Int, p: Int):Int {
        if(p=0) then
            1
        else
            i*powR(i, p-1)
        fi
    };

    powI(b: Int, p2: Int):Int {
        let f:Int <- 1, i: Int <- p2  in {
            while(not(i=0)) loop {
                f <- f * b;
                i <- i - 1;
            } pool;
            f;
        }
    };

};