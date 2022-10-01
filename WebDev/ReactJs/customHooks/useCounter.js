import { useState } from "react";

export default function useCounter(defaultValue = 0) {
  const [counter, setCounter] = useState(defaultValue);

  const increament = (step) => {
    setCounter(counter + step);
  };

  const decreament = (step) => {
    if (counter < step) {
      setCounter(0);
    } else {
      setCounter(counter - step);
    }
  };

  return [counter, increament, decreament];
}
