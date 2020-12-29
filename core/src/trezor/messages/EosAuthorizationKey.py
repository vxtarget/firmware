# Automatically generated by pb2py
# fmt: off
import protobuf as p

if __debug__:
    try:
        from typing import Dict, List  # noqa: F401
        from typing_extensions import Literal  # noqa: F401
    except ImportError:
        pass


class EosAuthorizationKey(p.MessageType):

    def __init__(
        self,
        *,
        address_n: List[int] = None,
        type: int = None,
        key: bytes = None,
        weight: int = None,
    ) -> None:
        self.address_n = address_n if address_n is not None else []
        self.type = type
        self.key = key
        self.weight = weight

    @classmethod
    def get_fields(cls) -> Dict:
        return {
            1: ('type', p.UVarintType, None),
            2: ('key', p.BytesType, None),
            3: ('address_n', p.UVarintType, p.FLAG_REPEATED),
            4: ('weight', p.UVarintType, None),
        }
