data Exp = Num Int
         | Add Exp Exp
         | Sub Exp Exp
         | Var String
         | App String Exp
  deriving Show

data Cmd = Atr String Exp     -- x = 1
        | Prt Exp            -- prt x
        | Seq Cmd Cmd        -- cmd1 ; cmd2
        | Cnd Exp Cmd Cmd    -- if cnd then cmd1 else cmd2
        | Fun String Cmd     -- def f: cmd
    deriving Show

-- 1.1
-- x = 1
-- y = 2
-- print(x + y)
(Atr "x" (Num 1))
(Atr "y" (Num 2))
Prt(Add (Var "x") (Var "y"))

-- 1.2
-- def duplica (x):
--     return x+x
-- print(duplica(10))
Seq (Fun "duplica" (Atr "x" (Add (Var "x") (Var "x")))) (Prt (App "duplica" (Num 10)))

-- 1.3
-- def soma (v):
--     if v != 0:
--         return v + soma(v-1)
--     else:
--         return 0
Seq (Fun "soma" (Cnd (Var "arg") 
                    (Atr "ret" (Add (Var "arg") (App "soma" (Sub (Var "arg") (Num 1)))))
                    (Atr "ret" (Num 0)))
                (Prt (App "soma" (Num 10))))