/**
 * This class is generated by jOOQ
 */
package classes.routines;


import classes.Public;

import javax.annotation.Generated;

import org.jooq.Field;
import org.jooq.Parameter;
import org.jooq.impl.AbstractRoutine;


/**
 * This class is generated by jOOQ.
 */
@Generated(
    value = {
        "http://www.jooq.org",
        "jOOQ version:3.8.6"
    },
    comments = "This class is generated by jOOQ"
)
@SuppressWarnings({ "all", "unchecked", "rawtypes" })
public class Test extends AbstractRoutine<Integer> {

    private static final long serialVersionUID = 1094711563;

    /**
     * The parameter <code>public.test.RETURN_VALUE</code>.
     */
    public static final Parameter<Integer> RETURN_VALUE = createParameter("RETURN_VALUE", org.jooq.impl.SQLDataType.INTEGER, false, false);

    /**
     * The parameter <code>public.test.one</code>.
     */
    public static final Parameter<String> ONE = createParameter("one", org.jooq.impl.SQLDataType.CLOB, false, false);

    /**
     * Create a new routine call instance
     */
    public Test() {
        super("test", Public.PUBLIC, org.jooq.impl.SQLDataType.INTEGER);

        setReturnParameter(RETURN_VALUE);
        addInParameter(ONE);
    }

    /**
     * Set the <code>one</code> parameter IN value to the routine
     */
    public void setOne(String value) {
        setValue(ONE, value);
    }

    /**
     * Set the <code>one</code> parameter to the function to be used with a {@link org.jooq.Select} statement
     */
    public void setOne(Field<String> field) {
        setField(ONE, field);
    }
}