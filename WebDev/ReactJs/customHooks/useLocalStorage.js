import { useState, useEffect } from "react";

export default function useLocalStorage(props) {
  const [localValue, setLocalValue] = useState();

  useEffect(() => {
    // Change local item value every time key changes
    const currentValue = localStorage.getItem(props.key);
    setLocalValue(currentValue);
  }, [props.key]);

  const getValue = () => {
    const item = localStorage.getItem(props.key);
    // Check if the item even exists
    if (item) {
      setLocalValue(JSON.parse(item));
      return JSON.parse(item);
    }

    return null;
  };

  const setValue = (newValue) => {
    setLocalValue(newValue);
    localStorage.setItem(props.key, JSON.stringify(newValue));
  };

  return {
    value: localValue,
    getValue,
    setValue,
  };
}
