import { useState } from "react";

export function useInput(intialValue) {
  const [value, setValue] = useState(intialValue);

  //Reset input
  const reset = () => {
    setValue(intialValue);
  };

  const bind = {
    value,
    onChange: (e) => {
      setValue(e.target.value);
    },
  };

  return [value, bind, reset];
}
